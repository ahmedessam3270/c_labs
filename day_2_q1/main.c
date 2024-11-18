#include <stdio.h>

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int increment(int size, int current) {
    return (current + 1) % size;
}

int decrement(int size, int current) {
    return (current - 1 + size) % size;
}

void drawBox(int x, int y, int size) {
    // Draw top border
    gotoxy(x-1, y-1);
    printf("┌");
    for(int i = 0; i < size*4; i++) printf("─");
    printf("┐");

    // Draw side borders
    for(int i = 0; i < size; i++) {
        gotoxy(x-1, y+i);
        printf("│");
        gotoxy(x+size*4, y+i);
        printf("│");
    }

    // Draw bottom border
    gotoxy(x-1, y+size);
    printf("└");
    for(int i = 0; i < size*4; i++) printf("─");
    printf("┘");
}

int main() {
    int size;

    printf("Enter the size of magic square (odd number): ");
    scanf("%d", &size);

    if (size % 2 == 0 || size < 1) {
        printf("Please enter an odd number greater than 0\n");
        return 1;
    }

    // Clear screen
    printf("\033[2J");

    // Starting position for the box
    int startX = 5;
    int startY = 3;

    // Draw the box first
    drawBox(startX, startY, size);

    int row = 0, col = size / 2;

    // Print first number
    gotoxy(startX + col*4, startY + row);
    printf("\033[1;36m%3d\033[0m", 1);  // Cyan color with padding

    for (int i = 2; i <= size * size; i++) {
        if ((i-1) % size != 0) {
            row = decrement(size, row);
            col = decrement(size, col);
        } else {
            row = increment(size, row);
        }
        gotoxy(startX + col*4, startY + row);

        // Change color based on number properties
        if (i % 2 == 0) {
            printf("\033[1;32m%3d\033[0m", i);  // Green for even numbers
        } else {
            printf("\033[1;33m%3d\033[0m", i);  // Yellow for odd numbers
        }
    }

    // Move cursor below the box
    gotoxy(1, startY + size + 2);

    return 0;
}
