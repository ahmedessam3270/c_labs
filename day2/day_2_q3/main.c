#include <stdio.h>

int main() {
    int choice;
    int validInput;


    printf("         MENU           \n");
    printf("  1. First Choice       \n");
    printf("  2. Second Choice      \n");
    printf("  3. Third Choice       \n");

    printf("\nEnter your choice (1-3): ");
    validInput = scanf("%d", &choice);

    if (validInput == 1) {
        if (choice >= 1 && choice <= 3) {
            printf("\nYou selected: ");

            switch(choice) {
                case 1:
                    printf("First Choice\n");
                    break;
                case 2:
                    printf("Second Choice\n");
                    break;
                case 3:
                    printf("Third Choice\n");
                    break;
            }
        } else {
            printf("\nInvalid choice! Please select between 1 and 3.\n");
        }
    } else {
        printf("\nInvalid input! Please enter a number.\n");

    }

    return 0;
}
