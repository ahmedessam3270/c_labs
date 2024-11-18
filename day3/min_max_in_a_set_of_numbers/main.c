#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size= 0 , i= 0;

    // Input array size
    printf("Enter the number of elements (1-%d): ", MAX_SIZE);
    scanf("%d", &size);

    // Validate size
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid array size!\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d numbers:\n", size);
    for (i = 0; i < size; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Find max and min
    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Display array elements
    printf("\nArray elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Display results
    printf("\nMinimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
