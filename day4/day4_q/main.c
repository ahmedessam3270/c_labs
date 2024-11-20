#include <stdio.h>
#include <stdlib.h>



#define ROW 3
#define COL 4


int main()
{
    // if you have a matrix of dimension 3 * 4
    //write a program to read it from the user
    //find the sum of each row.
    // find the average of each column

    // to initiate the matrix and fill it with 0 initially
    int matrix[ROW][COL] =  {0};

    // to have the inputs from the users
    for(int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
        printf("Enter data [%d] [%d]: ", i, j);
        scanf(" %d", &matrix[0][i*COL+j]);
        }
    }

    // to print the sum of each row
    for (int i = 0; i<ROW; i++){
        int rowSum = 0;
        int rowAvg = 0;
        for (int j = 0; j < COL; j++){
            rowSum+= matrix[i][j];
            rowAvg = (double)(rowSum) / (double)(COL);
        }
        printf("the sum of the %d row is: %d \n", i+1, rowSum);
        printf("the Average of the %d row is: %d \n", i+1, rowAvg);


    }



    /*
    for(int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            printf("data given %d * %d =  %d \n" , i,j, matrix[0][i*COL+j]);
        }
    }*/
    return 0;
}
