
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the first input as an integer
    int n;
    scanf("%d", &n);

    // Check if the input is 1
    if (n == 1) {
        // If the input is 1, print "Hello World"
        printf("Hello World\n");
    } else {
        // If the input is not 1, read two more strings
        char str1[100], str2[100];
        scanf("%s %s", str1, str2);

        // Parse the two strings as integers and print their sum
        int num1 = atoi(str1);
        int num2 = atoi(str2);
        printf("%d\n", num1 + num2);
    }

    // Close the BufferedReader
    return 0;
}

