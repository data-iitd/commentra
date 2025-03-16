#include <stdio.h> // Including standard input-output library
#include <limits.h> // Including limits.h for INT_MAX
#include <stdlib.h> // Including stdlib for dynamic memory allocation

int main() { // Main function to start the program
    int INF = INT_MAX; // Initializing INF with the maximum value of an integer

    int N; // Variable to store the number of elements in the array
    long X; // Variable to store the value of X
    scanf("%d", &N); // Reading the number of elements in the array from the console
    scanf("%ld", &X); // Reading the value of X from the console

    long *x = (long *)malloc(N * sizeof(long)); // Dynamically allocating an array of size N to store the elements
    long *xsum = (long *)malloc((N + 1) * sizeof(long)); // Dynamically allocating an array of size N+1 to store the sum of elements up to that index

    xsum[0] = 0; // Initializing the first element of xsum to 0
    for (int i = 0; i < N; i++) { // Loop to read and store the elements in the array
        scanf("%ld", &x[i]); // Reading the element into the array
        xsum[i + 1] = xsum[i] + x[i]; // Updating the sum of elements up to the current index
    }

    long ans = X * N + 5 * xsum[N]; // Initializing the answer with the first calculation

    for (int i = 1; i < N; i++) { // Loop to find the minimum cost
        long cost = X * i + 5 * (xsum[N] - xsum[N - i]); // Calculating the cost for the current i
        for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) { // Nested loop to check the cost for different j and k
            if (cost > ans) { // If the cost is greater than the current answer, break the loop
                break;
            }
            cost += j * (xsum[k] - xsum[k - i < 0 ? 0 : k - i]); // Updating the cost with the sum of elements between k and k-i
        }
        ans = (ans < cost) ? ans : cost; // Updating the answer with the minimum cost found so far
    }

    printf("%ld\n", ans + N * X); // Printing the final answer

    free(x); // Freeing the dynamically allocated memory for x
    free(xsum); // Freeing the dynamically allocated memory for xsum

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
