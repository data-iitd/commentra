
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Setting the scanner to scan words as tokens
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);

    // Reading the first integer 'a' from stdin
    int a = atoi(buf);

    // Reading the second integer 'b' from stdin
    fgets(buf, sizeof(buf), stdin);
    int b = atoi(buf);

    // Calculating the sum of 'a' and 'b'
    int ret = a + b;

    // Checking if the sum is less than the difference of 'a' and 'b'
    if (ret < (a - b)) {
        // If true, then update the value of'ret'
        ret = a - b;
    }

    // Checking if the sum is less than the product of 'a' and 'b'
    if (ret < (a * b)) {
        // If true, then update the value of'ret'
        ret = a * b;
    }

    // Printing the final value of'ret'
    printf("%d\n", ret);

    // End of the code
    return 0;
}
