#include <stdio.h>

#define MOD 1000000007
#define IO_BUFFER_SIZE 1024 * 1024

// Function to read the next integer from input
int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int main() {
    // Read the values of h and n from input
    int h = nextInt();
    int n = nextInt();
    int a = 0; // Initialize a variable to accumulate the sum of integers

    // Loop to read n integers and accumulate their sum
    for (int i = 0; i < n; i++) {
        a += nextInt();
    }

    // Check if the accumulated sum is less than h
    if (h > a) {
        // If h is greater than the sum, print "No"
        printf("No\n");
    } else {
        // Otherwise, print "Yes"
        printf("Yes\n");
    }

    return 0;
}

// <END-OF-CODE>
