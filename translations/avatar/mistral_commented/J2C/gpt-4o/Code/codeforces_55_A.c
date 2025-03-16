#include <stdio.h>  // Including standard input-output library
#include <stdbool.h> // Including library for boolean type

int main() {
    int n, i = 1, k = 0, p = 1;  // Declaring and initializing variables
    bool flag = true;  // Initializing the boolean variable 'flag' to true
    int a[1000] = {0};  // Declaring and initializing an integer array of size 1000

    scanf("%d", &n);  // Reading the first integer from standard input and assigning it to 'n'

    while (k <= n) {  // Starting a while loop that runs as long as 'k' is less than or equal to 'n'
        i += k;  // Incrementing the variable 'i' by the value of 'k'

        if (i >= n) {  // Checking if the value of 'i' is greater than or equal to 'n'
            while (i >= n) i -= n;  // If yes, then decrement 'i' by 'n' until it becomes less than 'n'
        }

        a[i]++;  // Incrementing the value of the 'i'-th element of the array 'a' by 1
        k++;  // Incrementing the variable 'k' by 1
    }

    for (i = 0; i < n; ++i) {  // Starting a for loop that runs from 0 to 'n'-1
        if (a[i] == 0) {  // Checking if the 'i'-th element of the array 'a' is equal to 0
            flag = false;  // If yes, then set the boolean variable 'flag' to false
            break;  // Exiting the for loop
        }
    }

    if (flag) printf("YES\n");  // If the boolean variable 'flag' is still true after the for loop, then print "YES"
    else printf("NO\n");  // Otherwise, print "NO"

    return 0;  // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
