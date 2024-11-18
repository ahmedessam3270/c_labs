
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(x) Sleep(x)
    #define CLEAR_SCREEN system("cls")
#else
    #include <unistd.h>
    #define SLEEP_MS(x) usleep(x * 500)
    #define CLEAR_SCREEN system("clear")
#endif

#include <stdio.h>

#ifdef _WIN32
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#else
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
#endif

int increment(int size, int current) {
    return (current + 1) % size;
}

int decrement(int size, int current) {
    return (current - 1 + size) % size;
}

void drawBox(int x, int y, int size) {
    // Draw top border
    gotoxy(x-1, y-1);
    printf("+");
    for(int i = 0; i < size*4; i++) printf("-");
    printf("+");

    // draw the containing borders (left and right borders)
    for(int i = 0; i < size; i++) {
        gotoxy(x-1, y+i);
        printf("|");
        gotoxy(x+size*4, y+i);
        printf("|");
    }

    // draw the containing border (up and down borders)
    gotoxy(x-1, y+size);
    printf("+");
    for(int i = 0; i < size*4; i++) printf("-");
    printf("+");
    fflush(stdout);
}


int main() {
    int size;

    printf("Enter the size of magic square (odd number): ");
    scanf("%d", &size);

    if (size % 2 == 0 || size < 1) {
        printf("Please enter an odd number greater than 0\n");
        return 1;
    }

    CLEAR_SCREEN;

    // Starting position for the box
    int startX = 5;
    int startY = 3;

    // Draw the box first
    drawBox(startX, startY, size);

    // Add header
    gotoxy(startX, startY - 2);
    printf("Magic Square Animation (size: %d x %d)", size, size);

    int row = 0, col = size / 2;

    // Print first number with animation
    gotoxy(startX + col*4, startY + row);
    printf("%3d", 1);
    fflush(stdout);
    SLEEP_MS(1000);

    for (int i = 2; i <= size * size; i++) {
        if ((i-1) % size != 0) {
            row = decrement(size, row);
            col = decrement(size, col);
        } else {
            row = increment(size, row);
        }

        fflush(stdout);
        gotoxy(startX + col*4, startY + row);
        printf("%3d", i);
        fflush(stdout);

        SLEEP_MS(500);
    }


    printf("\n\nMagic Square completed!\n");

    return 0;
}

