
#include <stdio.h>
#include <string.h>

// This function generates a string of numbers from 1 to 1000
char *generateString() {
    char *str = (char *)malloc(1001 * sizeof(char));
    int i;
    for (i = 0; i < 1001; i++) {
        str[i] = i + '0';
    }
    return str;
}

// The main function reads an integer n from the user, and prints the nth character of the generated string
int main() {
    int n;
    scanf("%d", &n);
    printf("%c", generateString()[n - 1]);
    return 0;
}

