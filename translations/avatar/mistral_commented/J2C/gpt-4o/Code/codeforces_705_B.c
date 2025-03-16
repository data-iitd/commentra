#include <stdio.h>

int prevWinner = 0;  // Initializing the 'prevWinner' variable to 0

void solve() {
    int t;
    scanf("%d", &t);  // Reading the number of test cases
    int arr[t];  // Creating an integer array of size 't' to store the input

    for (int i = 0; i < t; i++) {  // Iterating through the array
        scanf("%d", &arr[i]);  // Reading each element

        if (arr[i] == 1) {  // Checking if the current element is 1
            if (prevWinner == 0) {  // If the previous winner was 0
                prevWinner = 2;  // Update the 'prevWinner' variable to 2
            }

            if ((i - 1) % 2 == 0) {  // Checking the parity of the current element's index
                printf("%d\n", prevWinner == 0 ? 2 : 1);  // Printing the output based on the 'prevWinner' value
                prevWinner = (prevWinner == 0 ? 2 : 1);  // Updating the 'prevWinner' variable for the next iteration
            }
        }
    }
}

int main() {
    int t = 1;  // Initializing the test case counter

    while (t-- > 0) {  // Running the solution process for all test cases
        solve();
    }

    return 0;
}

// <END-OF-CODE>
