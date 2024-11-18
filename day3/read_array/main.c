#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int array[MAX_SIZE];
    int size = 0, cols = 0;

    // Ask the user to enter the size of the array
    do {
        printf("Enter the size of the array (1-100): ");
        scanf("%d", &size);

        if (size < 1 || size > 100) {
            printf("Invalid size! Please enter a number between 1 and 100.\n");
        }
    } while (size < 1 || size > 100);

    // Get valid number of columns from user
    do {
        printf("Enter the number of columns (must be a factor of %d): ", size);
        scanf("%d", &cols);

        if (cols < 1 || cols > size) {
            printf("Invalid number of columns! Must be between 1 and %d.\n", size);
        } else if (size % cols != 0) {
            printf("Invalid! %d must be divisible by the number of columns.\n", size);
        }
    } while (cols < 1 || cols > size || size % cols != 0);

    int rows = size / cols;

    // Input array elements
    printf("\nEnter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        printf("Enter element [%d,%d]: ", i/cols + 1, i%cols + 1);
        scanf("%d", &array[i]);
    }

    // Display as 2D matrix
    printf("\nThe %dx%d matrix is:\n", rows, cols);
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            printf(" %3d ", array[row * cols + col]);
        }
        printf("\n");
    }

    // Display factors of size to help user
    printf("\nValid numbers of columns for size %d are: ", size);
    for(int i = 1; i <= size; i++) {
        if (size % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
