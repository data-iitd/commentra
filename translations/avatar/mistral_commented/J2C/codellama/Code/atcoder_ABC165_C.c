
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *a = NULL; // Declaring and initializing four integer arrays a, b, c, and d to null
int *b = NULL;
int *c = NULL;
int *d = NULL;
int n = 0; // Declaring and initializing two integer variables n and m to zero
int m = 0;
int q = 0; // Declaring and initializing an integer variable q to zero
long ans = -100L; // Declaring and initializing a long variable ans to a very large negative number

void dfs(int *list, int size) { // A recursive function named dfs that takes an integer array named list and an integer variable named size as arguments
    if (size == n) { // A conditional statement that checks if the size of the integer array list is equal to the integer variable n
        long score = 0L; // Declaring and initializing a long variable score to zero

        for (int i = 0; i < q; ++i) { // A for loop that calculates the score based on the condition that (list[b[i]] - list[a[i]] == c[i])
            score += (list[b[i]] - list[a[i]] == c[i]) ? d[i] : 0L;
        }

        ans = (ans > score) ? ans : score; // Updating the value of the long variable ans with the maximum value of ans and the score calculated in the for loop
        return; // Returning from the function after updating the value of ans
    }

    if (size > 0) { // A conditional statement that checks if the size of the integer array list is greater than zero
        for (int num = list[size - 1] + 1; num <= m; ++num) { // A for loop that adds the integer num to the integer array list and recursively calls the function dfs
            list[size] = num;
            dfs(list, size + 1);
        }
    } else { // If the size of the integer array list is zero
        for (int num = 1; num <= m; ++num) { // A for loop that adds the integer num to the integer array list and recursively calls the function dfs
            list[size] = num;
            dfs(list, size + 1);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &q); // Reading the first three integers n, m, and q from the standard input

    a = (int *)malloc(q * sizeof(int)); // Allocating memory for the array a of size q and initializing it to null
    b = (int *)malloc(q * sizeof(int)); // Allocating memory for the array b of size q and initializing it to null
    c = (int *)malloc(q * sizeof(int)); // Allocating memory for the array c of size q and initializing it to null
    d = (int *)malloc(q * sizeof(int)); // Allocating memory for the array d of size q and initializing it to null

    for (int i = 0; i < q; ++i) { // A for loop that reads q integers from the standard input and stores them in arrays a, b, c, and d
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        a[i] -= 1;
        b[i] -= 1;
    }

    int *list = (int *)malloc((n + 1) * sizeof(int)); // Allocating memory for the integer array list of size n + 1 and initializing it to null

    dfs(list, 0); // Calling the recursive function dfs with an integer array list of size n + 1 and an integer variable size equal to zero

    printf("%ld\n", ans); // Printing the value of the long variable ans to the standard output

    free(a); // Freeing the memory allocated for the arrays a, b, c, and d
    free(b);
    free(c);
    free(d);
    free(list); // Freeing the memory allocated for the integer array list

    return 0; // Returning zero to the operating system
}

