#include <stdio.h>
#include <stdlib.h>

int main() {

    // to make a program that takes a number from the user
    // 1st, check this number must be lower than 100
    // if the given number is larger than 100, return
    // 2st, add this number to himself and check if the new number exceeds the 100 or not


    int sum = 0;
    int number = 0;
    int validInput = 0;

    printf("Enter numbers (program will exit when sum exceeds 100)\n");

    while (sum <= 100) {

        //printf("Current sum: %d\n", sum);
        //printf("Enter a number: ");
        fflush(stdin);
        scanf(" %d", &number);

        if (number > 0 ) {
            sum += number;

        } else {
            printf("Invalid input. Please enter a number.\n");
        }
    }

    return 0;
}
