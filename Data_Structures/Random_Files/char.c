#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000 // Maximum input size
#define MINLINE 8

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        char* arr = (char*)malloc(len * sizeof(char));
        int k = 0;
        for (int j = len-1; j >= 0; j--) {
            arr[k] = line[j];
            k++;
        }
        if (len > max) {
            for (int i=0; i<len; i++) {
                printf("%c", line[i]);
            }
            printf("\n");
            for (int p=0; p<len; p++) {
                printf("%c", arr[p]);
            }
            printf("\n");
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%s\n", longest);
        printf("%d\n", (max-1));
    return 0;
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim) {
    int c, i;

    int leng = 0;

    for (i = 0; (c=getchar()) != EOF && c!='\n'; ++i) {
        s[i] = c;
        leng++;
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