

#include <bits/stdc++.h>  // Include necessary utility libraries

using namespace std ;  // Using the standard namespace

int main() {
    int t ;  // Declaring the variable 't' to store the number of test cases

    cin >> t ;  // Reading the number of test cases from the input

    int arr[t] ;  // Creating an integer array of size 't' to store the input

    for (int i = 0; i < t; i++) {  // Iterating through the array
        cin >> arr[i] ;  // Reading each element from the input

        if (arr[i] == 1) {  // Checking if the current element is 1
            if (prevWinner == 0) {  // If the previous winner was 0
                prevWinner = 2 ;  // Update the 'prevWinner' variable to 2
            }

            if ((arr[i] - 1) % 2 == 0) {  // Checking the parity of the current element's index
                cout << (prevWinner == 0? 2 : 1) << endl ;  // Printing the output based on the 'prevWinner' value
                prevWinner = (prevWinner == 0? 2 : 1) ;  // Updating the 'prevWinner' variable for the next iteration
            }
        }
    }

    return 0 ;  // Returning 0 to indicate successful execution
}

