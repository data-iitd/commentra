#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* generateString() {
    char* sb = (char*)malloc(10000 * sizeof(char)); // Allocate memory for the string
    int index = 0;
    for (int i = 1; i <= 1000; i++) {
        char num[10];
        sprintf(num, "%d", i); // Convert integer to string
        int len = strlen(num);
        for (int j = 0; j < len; j++) {
            sb[index++] = num[j];
        }
    }
    sb[index] = '\0'; // Null-terminate the string
    return sb;
}

int main() {
    int n;
    scanf("%d", &n);
    char* str = generateString();
    printf("%c\n", str[n - 1]);
    free(str); // Free the allocated memory
    return 0;
}
