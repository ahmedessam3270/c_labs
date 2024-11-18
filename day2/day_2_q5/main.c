#include <stdio.h>

int main() {
    int table = 0, multiplier= 0;


    printf("Multiplication Tables (10-1)\n\n");

    for (table = 10; table >= 1; table--) {
        // Print table header
        printf("Table %d:\n", table);
        printf("----------\n");

        // Print multiplications
        for (multiplier = 12; multiplier >= 1; multiplier--) {
            printf("%2d × %2d = %3d\n",
                   table, multiplier, table * multiplier);
        }

        // Print separator except after the last table
        if (table > 1) {
            printf("\n");
            for (int i = 0; i < 20; i++) {
                printf("*");
            }
            printf("\n\n");
        }
    }

    return 0;
}
