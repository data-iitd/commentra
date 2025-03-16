
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 100

int main ( ) {
    // Reading the number of inputs
    int n = 0;
    scanf("%d", &n);

    // Processing the input based on the value of n
    if (n == 1) {
        // Outputting "Hello World" if n is 1
        printf("Hello World\n");
    } else {
        // Reading two strings and calculating their sum if n is not 1
        char str1[MAX_INPUT_LEN];
        char str2[MAX_INPUT_LEN];
        scanf("%s", str1);
        scanf("%s", str2);
        int sum = atoi(str1) + atoi(str2);
        printf("%d\n", sum);
    }

    return 0;
}

