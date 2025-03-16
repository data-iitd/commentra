// Constants and package imports
#include <stdio.h>
#include <stdlib.h>

const int mod = 1000000007;
const int ioBufferSize = 1024 * 1024;

int main() {
    // Reading the first two integers h and n
    int h, n;
    scanf("%d %d", &h, &n);

    // Initializing variable a to 0
    int a = 0;

    // Iterating through the array of size n and adding each integer to variable a
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        a += temp;
    }

    // Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
    if (h > a) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}
// <END-OF-CODE>
