

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Reading the number of inputs
    int n;
    scanf("%d", &n);

    // Processing the input based on the value of n
    if (n == 1) {
        // Outputting "Hello World" if n is 1
        printf("Hello World\n");
    } else {
        // Reading two strings and calculating their sum if n is not 1
        char str1[100], str2[100];
        scanf("%s %s", str1, str2);
        int sum = atoi(str1) + atoi(str2);
        printf("%d\n", sum);
    }

    return 0;
}

// END-OF-CODE