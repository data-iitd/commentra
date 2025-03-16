#include <stdio.h> // Including the standard input-output library

int main() {
    int n, k; // Declaring variables n and k
    scanf("%d", &n); // Reading the first integer n from standard input
    scanf("%d", &k); // Reading the second integer k from standard input
    int i = 1, req = 1; // Initializing two variables i and req with the value 1

    // Starting a while loop that continues as long as k - req is greater than or equal to 0
    while (k - req >= 0) {
        if (k - req >= 0) { // Checking if k - req is greater than or equal to 0
            k = k - req; // If it is, updating the value of k by subtracting the value of req
        } else {
            break; // If k - req is less than 0, breaking out of the while loop
        }
        i++; // Incrementing the value of i by 1

        if (i % n != 0) { // Checking if the remainder of i divided by n is not equal to 0
            req = i % n; // If it is not, updating the value of req to the remainder of i divided by n
        } else {
            req = n; // If the remainder is equal to 0, updating the value of req to n
        }
    }

    // Printing the value of k to the standard output
    printf("%d\n", k);
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
