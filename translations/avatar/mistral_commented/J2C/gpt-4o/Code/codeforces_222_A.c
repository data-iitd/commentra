#include <stdio.h> // Including the standard input-output library

int main() { // Defining the main function
    int n, k; // Declaring variables n and k
    scanf("%d %d", &n, &k); // Reading the first two integers from the input

    int l = 0, c = 1; // Initializing the variables l and c with values 0 and 1 respectively

    for (int i = 0; i < n; i++) { // Starting a for loop that iterates n times
        int a; // Declaring variable a
        scanf("%d", &a); // Reading the next integer from the input and assigning it to variable a

        if (a == l) c += 1; // If the current integer is equal to the previous one, increment the counter c by 1
        else c = 1; // Otherwise, reset the counter c to 1

        l = a; // Assigning the current integer to the previous integer variable l
    }

    if (c + k > n) { // Checking if the sum of counter c and integer k is greater than the total number of integers n
        printf("%d\n", n - c); // If true, print the difference between n and c
    } else {
        printf("-1\n"); // If false, print -1
    }

    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
