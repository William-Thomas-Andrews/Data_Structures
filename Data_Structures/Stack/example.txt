#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 10 // Maximum input size
#define MINLINE 8

int my_getline(char s[], int lim);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    printf("len %d\n", len);
    while ((len = my_getline(line, MAXLINE)) > 0) {

        int k = 0;

        int marker_index = 0;

        

        for (int h=MAXLINE-1; h>=0; h--) {
            if (line[h] == '\t' || line[h] == ' ') {
                marker_index = h;
                break;
            }
        }
        
        for (int i=0; i<len; i++) {
            char z = line[i];
            // printf("Maerker %d\n", marker_index);
            if (i == marker_index) {
                printf("marker\n");
                // i++;
            }
            else {
                printf("%c", z);
            }
            
            
        }
        printf("\n");
    }
    return 0;
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim) {
    int c, i;

    for (i = 0; (c=getchar()) != EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}