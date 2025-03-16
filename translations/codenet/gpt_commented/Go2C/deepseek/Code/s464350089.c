#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define IO_BUFFER_SIZE 1048576

int main() {
    // Initialize a buffered reader for reading input
    char *buffer = (char *)malloc(IO_BUFFER_SIZE * sizeof(char));
    setvbuf(stdin, buffer, _IOFBF, IO_BUFFER_SIZE);

    // Read the values of h and n from input
    int h, n;
    scanf("%d %d", &h, &n);

    // Initialize a variable to accumulate the sum of integers
    int a = 0;

    // Loop to read n integers and accumulate their sum
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a += num;
    }

    // Check if the accumulated sum is less than h
    if (h > a) {
        // If h is greater than the sum, print "No"
        printf("No\n");
    } else {
        // Otherwise, print "Yes"
        printf("Yes\n");
    }

    // Free the allocated buffer
    free(buffer);

    return 0;
}
