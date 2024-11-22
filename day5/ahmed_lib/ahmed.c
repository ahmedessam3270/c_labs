#define TERMINATOR '\0'


int ahmed_strlen_int (char str[]){
    int i = 0;
    while (str[i] != TERMINATOR){
        i++;
    }
    return i;
}


void ahmed_strcpy_void (char destination[], char source[], int destinationSize){
    int i = 0;
    if (ahmed_strlen_int(source) <= destinationSize -1){
        printf("Valid size \n");
        while (source[i] != TERMINATOR){
            destination[i] = source[i];
            i++;
        }
        destination[i]= TERMINATOR;
    } else {
        printf("Error, source > destination \n");
    }
}

void ahmed_strcat_void (char destination[], char source[]){
    int i = 0;
    int j = 0;
    while (destination[i] != TERMINATOR){
        i++;
    }

    while (source[j] != TERMINATOR){
        destination[i] = source[j];
        i++;
        j++;
    }

    destination[i] = TERMINATOR;
}

char ahmed_strcmp_char (char str1[], char str2[]){
    int i = 0;
    while (str1[i] != TERMINATOR && str2[i] != TERMINATOR){
        if (str1[i] != str2[i]){
            return 0;
        }
        i++;
    }
    if (str1[i] == TERMINATOR && str2[i] == TERMINATOR){
        return 1;
    } else {
        return 0;
    }
}   

void ahmed_strLowerToUpper_void (char str[]){
    int i = 0;
    while (str[i] != TERMINATOR){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
        i++;
    }
}

void ahmed_strUpperToLower_void (char str[]){
    int i = 0;
    while (str[i] != TERMINATOR){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
        i++;
    }
}   