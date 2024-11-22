
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ahmed.h"
#include "ahmed.c"




int main()
{
   //char str[10] = {'A','h','m','e','d','\0', 's'};
   //char str2[6]= "ahmed";
   //int i = 0;
   /*
   while(str[i] != '\0'){
   printf("%c", str[i]);
   i++;
   }*/

   //printf("%s\n", &str2[1]); // you give the pointer of the array (address of the first element)
   // its behavior is exactly the previous while loop

   /*
   char str[20]={0};

   printf("Please enter you full name: ");
   // SUPER IMPORTANT
   scanf("%[^\n]s", str); // this doesn't take the words after the white space
   printf("%s", str);
   */

   /*
   char str[20] = {0};
   scanf("%[^\n]s", str);

  char stringLength = strlen(str);

  printf("\n%d\n", stringLength);
  */

  /*
   char str[20] = {0};
   scanf("%[^\n]s", str);

  char stringLength = ahmed_strlen(str);

  printf("\n%d\n", stringLength);

    char name1[DEST_SIZE]= "ahmed";
    char name2[10] = "essam";
    printf("before strcpy name1 = %s \n", name1);
    ahmed_strcpy(name1, name2, DEST_SIZE);
    printf("after strcpy name1 = %s \n", name1);
*/


    // first lets test the ahmed_strcpy_void function
    printf("Testing ahmed_strcpy_void function \n");
    char name1[20]= "ahmed";
    char name2[10] = "essam";


    printf("before strcpy name1 = %s \n", name1);
    ahmed_strcpy_void(name1, name2, 20);
    printf("after strcpy name1 = %s \n", name1);

    printf(" *************************************** \n");

    printf("testing ahmed_strcat_void function \n");
    char name3[20]= "ahmed";
    char name4[10] = "essam";
    ahmed_strcat_void(name3, name4);
    printf("after strcat name3 = %s \n", name3);

    printf(" *************************************** \n");

    printf("testing ahmed_strcmp_char function \n");
    char name5[20]= "ahmed";    
    char name6[10] = "ahmed";
    char result = ahmed_strcmp_char(name5, name6);
    printf("result = %d \n", result);
    
    printf(" *************************************** \n");

    printf("testing ahmed_strLowerToUpper_void function \n");

    char name7[20]= "ahmed";
    printf("before strLowerToUpper name7 = %s \n", name7);
    ahmed_strLowerToUpper_void(name7);
    printf("after strLowerToUpper name7 = %s \n", name7);

    printf(" *************************************** \n");

    printf("testing ahmed_strUpperToLower_void function \n");

    char name8[20]= "AHMED";
    printf("before strUpperToLower name8 = %s \n", name8);
    ahmed_strUpperToLower_void(name8);
    printf("after strUpperToLower name8 = %s \n", name8);

    printf(" *************************************** \n");
    

    return 0;
}






