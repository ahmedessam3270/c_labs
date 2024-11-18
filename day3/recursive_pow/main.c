#include <stdio.h>
#include <stdlib.h>

int powerUp(int base, int power)
{
    if (base <= 0) return 1;
    else if (power <= 0) return 1;
    return base * powerUp(base , power - 1);
}

int main()
{
    int base = 0;
    int power = -1;

    while (base <= 0) {
        printf("Please Enter Base Number: ");
        scanf("%d", &base);
        if (base <= 0) printf("Wrong Number Try Again: ");
    }

    while(power < 0) {
        printf("Please Enter The power: ");
        scanf("%d", &power);
        if (power <= 0) printf("please enter positive power or 0,(Not Negative) \n");
    }


    printf("power is %d", powerUp(base, power));

    return 0;
}
