#include <stdio.h>
#include <stdlib.h>

int *a = NULL; // Declaring and initializing four integer arrays a, b, c, and d to null
int *b = NULL;
int *c = NULL;
int *d = NULL;
int n = 0; // Declaring and initializing two integer variables n and m to zero
int m = 0;
int q = 0; // Declaring and initializing an integer variable q to zero
long ans = -100L; // Declaring and initializing a long variable ans to a very large negative number

void dfs(int *list, int size) { // A recursive function named dfs that takes an array and its size as arguments
    if (size == n) { // A conditional statement that checks if the size of the array list is equal to the integer n
        long score = 0L; // Declaring and initializing a long variable score to zero

        for (int i = 0; i < q; ++i) { // A for loop that calculates the score based on the condition that (list[b[i]] - list[a[i]] == c[i])
            score += (list[b[i]] - list[a[i]] == c[i]) ? d[i] : 0L;
        }

        ans = (ans > score) ? ans : score; // Updating the value of the long variable ans with the maximum value of ans and the score calculated in the for loop
        return; // Returning from the function after updating the value of ans
    }

    int start = (size > 0) ? list[size - 1] : 1; // Determine the starting number based on the current size of the list
    for (int num = start; num <= m; ++num) { // A for loop that adds the integer num to the array list and recursively calls the function dfs
        list[size] = num; // Add num to the list
        dfs(list, size + 1); // Recursive call with increased size
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &q); // Reading the first three integers n, m, and q from the standard input

    a = (int *)malloc(q * sizeof(int)); // Allocating memory for the array a of size q
    b = (int *)malloc(q * sizeof(int)); // Allocating memory for the array b of size q
    c = (int *)malloc(q * sizeof(int)); // Allocating memory for the array c of size q
    d = (int *)malloc(q * sizeof(int)); // Allocating memory for the array d of size q

    for (int i = 0; i < q; ++i) { // A for loop that reads q integers from the standard input and stores them in arrays a, b, c, and d
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        a[i]--; // Subtracting 1 from a[i]
        b[i]--; // Subtracting 1 from b[i]
    }

    int *list = (int *)malloc(n * sizeof(int)); // Allocating memory for the list
    dfs(list, 0); // Calling the recursive function dfs with an empty list

    printf("%ld\n", ans); // Printing the value of the long variable ans to the standard output

    // Free allocated memory
    free(a);
    free(b);
    free(c);
    free(d);
    free(list);

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
