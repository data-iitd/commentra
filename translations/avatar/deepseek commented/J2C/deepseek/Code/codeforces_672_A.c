#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function generates a string of numbers from 1 to 1000
char* generateString() {
    int size = 1000;
    char* str = (char*)malloc((size + 1) * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    int index = 0;
    for (int i = 1; i <= 1000; i++) {
        char num[10];
        sprintf(num, "%d", i);
        int len = strlen(num);
        memcpy(str + index, num, len);
        index += len;
    }
    str[index] = '\0';
    return str;
}

// The main function reads an integer n from the user, and prints the nth character of the generated string
int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    char* str = generateString();
    printf("%c\n", str[n - 1]);
    free(str);
    return 0;
}

