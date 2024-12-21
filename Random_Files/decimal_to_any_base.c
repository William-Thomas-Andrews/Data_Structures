#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

/*
This file converts any positive integer (n) to any base (b).
*/


// int CalculateDigits(DecimalNumber, Base);
void format_string(char c[]);
void itob(int s[], int DecimalNumber, int Base, int digits);
void digits_to_char(int s[], char c[]);


int main() {
    int DecimalNumber = 255;
    int Base = 14;
    int s[MAXLEN] = {0};
    char c[MAXLEN+1];
    for (int j = 0; j < MAXLEN - 1; j++) {
        c[j] = '0'; // Set each character to '0'
    }
    c[MAXLEN - 1] = '\0'; // Null terminator
    itob(s, DecimalNumber, Base, MAXLEN);
    int size = sizeof(s) / sizeof(s[0]);
    for (int i = 0; i < size; i++) {
        printf("%d", s[i]);
    }
    printf("\n");
    digits_to_char(s, c);
    for (int k = 0; k < MAXLEN; k++) {
        printf("%c", c[k]);
    }
    printf("\n");
    format_string(c);
}

// int CalculateDigits(DecimalNumber, Base) {
//     if (DecimalNumber == 0) {
//         return 1;  //# Only one digit (zero)
//     }
//     int DigitsCount = 0;
//     while (DecimalNumber > 0) {
//         DecimalNumber = DecimalNumber; // Base
//         DigitsCount++;
//     }
//     return DigitsCount;
// }

void format_string(char c[]) {

    int flag = 0;
    int i = 0;

    do
    {
        if (c[i] != '0') 
        {
            flag = 1;
        }
    
        else if (i == (MAXLEN-1)) 
        {
            flag == 1;
        }
        
        i++;

    } while (flag == 0);

    i--;

    for (int j = i; j < MAXLEN; j++)
    {
        printf("%c", c[j]);
    }
}

void digits_to_char(int s[], char c[]) {
    for (int i = 0; i < MAXLEN; i++) {
        if (s[i] <= 9) {
            // printf("%c\n", (s[i] + '0'));
            c[i] = s[i] + '0';
        }
        else {
            switch(s[i]) {
                case 10:
                    c[i] = 'A';
                    break;
                case 11:
                    c[i] = 'B';
                    break;
                case 12:
                    c[i] = 'C';
                    break;
                case 13:
                    c[i] = 'D';
                    break;
                case 14:
                    c[i] = 'E';
                    break;
                case 15:
                    c[i] = 'F';
                    break;
                default:
                    break;
            }
        }
        
    }
}


void itob(int s[], int DecimalNumber, int Base, int digits) {
    int index = digits-1;
    while (DecimalNumber > 0) {
        s[index] = DecimalNumber % Base;
        DecimalNumber /= Base; 
        index--;
    }

    return;
}
    