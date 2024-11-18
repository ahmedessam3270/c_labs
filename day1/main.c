#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 2
    int integar_num = 2;
    float float_num = 2.2f;
    char letter = 'A';
    printf("the inegar_num = %d \t the float_num= %.2f \t the letter= %c\n", integar_num, float_num, letter);

    //3
    char input_letter;
    printf("please enter the letter you want: ");
    scanf("%c", &input_letter);

    printf("you inputed letter was %c\n", input_letter);
    printf("and its ACII is %d \n" , input_letter);

    //4

    int outputted_int;
    printf("enter your desired number you want to get the equivalent of it in hexadecimal and ocatdecimal: ");
    scanf("%d", &outputted_int);

    printf("the octal representation of the %d is: %o \n", outputted_int ,outputted_int);
    printf("the hexadecimal representation of the %d is: %x \n", outputted_int ,outputted_int);

    return 0;
}
