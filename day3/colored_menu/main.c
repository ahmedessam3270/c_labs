#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define MAXOPTIONS 3
#define clear() printf("\033[H\033[J")

// Enter and Esc
#define ESC 27
#define ENTER 10

// colors used in the program
#define COLOR_RESET   "\033[0m"
#define COLOR_TEAL    "\033[38;2;0;128;128m"
#define COLOR_WHITE   "\033[37m"

// list items
char menuOptions[MAXOPTIONS][20] = {
    "Ahmed",
    "Essam",
    "Mohamed"
};

typedef enum {
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_ENTER,
    KEY_ESC,
    KEY_OTHER
} KeyType;


KeyType getKey() {
    int ch = getchar();

    if (ch == ESC) {
        int next = getchar();
        if (next == '[') {
            ch = getchar();
            switch (ch) {
                case 'A': return KEY_UP;
                case 'B': return KEY_DOWN;
                case 'C': return KEY_RIGHT;
                case 'D': return KEY_LEFT;
            }
        }
        return KEY_ESC;
    }
    else if (ch == ENTER) {
        return KEY_ENTER;
    }

    return KEY_OTHER;
}

void initTerminal() {
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);
}

void resetTerminal() {
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);
}

void showMenu(int selected, int isSelected) {
    clear();

    if (isSelected) {
        printf("%s%s%s\n", COLOR_TEAL, menuOptions[selected-1], COLOR_RESET);
    } else {
        for (int i = 0; i < MAXOPTIONS; i++) {
            if (i + 1 == selected) {
                printf("%s%s%s\n", COLOR_TEAL, menuOptions[i], COLOR_RESET);
            } else {
                printf("%s%s%s\n", COLOR_WHITE, menuOptions[i], COLOR_RESET);
            }
        }
    }
    fflush(stdout);
}

int handleSelectRange(int current) {
    if (current < 1) return MAXOPTIONS;
    if (current > MAXOPTIONS) return 1;
    return current;
}

int main() {
    int selected = 1;
    int isSelected = 0;
    int running = 1;

    initTerminal();
    atexit(resetTerminal);

    showMenu(selected, isSelected);

    while (running) {
        KeyType key = getKey();

        switch (key) {
            case KEY_UP:
            case KEY_LEFT:
                if (!isSelected) {
                    selected = handleSelectRange(selected - 1);
                    showMenu(selected, isSelected);
                }
                break;

            case KEY_DOWN:
            case KEY_RIGHT:
                if (!isSelected) {
                    selected = handleSelectRange(selected + 1);
                    showMenu(selected, isSelected);
                }
                break;

            case KEY_ENTER:
                isSelected = 1;
                showMenu(selected, isSelected);
                break;

            case KEY_ESC:
                if (isSelected) {
                    isSelected = 0;
                    showMenu(selected, isSelected);
                } else {
                    clear();
                    running = 0;
                }
                break;

            default:
                break;
        }
    }

    return 0;
}
