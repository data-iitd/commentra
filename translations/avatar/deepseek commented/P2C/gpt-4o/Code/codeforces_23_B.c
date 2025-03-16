#include <stdio.h>

int main() {
    int n;  // Variable to store the number of iterations.
    scanf("%d", &n);  // Taking an integer input `n`.
    
    for (int i = 0; i < n; i++) {  // Looping `n` times.
        int a;  // Variable to store the integer input for each iteration.
        scanf("%d", &a);  // Taking an integer input `a`.
        
        if (a < 2) {  // Checking if `a` is less than 2.
            printf("0\n");  // Printing 0 if `a` is less than 2.
        } else {  // If `a` is not less than 2.
            printf("%d\n", a - 2);  // Printing the result of `a - 2`.
        }
    }
    
    return 0;  // Returning 0 to indicate successful execution.
}

// <END-OF-CODE>
