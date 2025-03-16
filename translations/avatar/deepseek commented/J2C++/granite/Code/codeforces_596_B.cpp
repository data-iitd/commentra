

#include <bits/stdc++.h> // Step 1: Include the necessary C++ utility headers.
using namespace std ; // Step 2: Define the Main function.
int main ( ) { // Step 3: Implement the main function.
    ios_base::sync_with_stdio ( false ) ; // Step 4: Disable synchronization between C and C++.
    cin.tie ( NULL ) ; // Step 5: Disable the use of buffering for input operations.
    int n ; // Step 6: Declare the variables required to read the input.
    cin >> n ; // Step 7: Read the size of the array from the user.
    long long arr [ n ] ; // Step 8: Create an array to store the elements of the array.
    for ( int i = 0 ; i < n ; i ++ ) { // Step 9: Read the elements of the array from the user.
        cin >> arr [ i ] ; 
    }
    long long answer = abs ( arr [ 0 ] ) ; // Step 10: Initialize a variable to store the answer.
    for ( int i = 1 ; i < n ; i ++ ) { // Step 11: Calculate the absolute difference between consecutive elements and add it to the answer.
        answer += abs ( arr [ i ] - arr [ i - 1 ] ) ; 
    }
    cout << answer << endl ; // Step 12: Print the final answer.
    return 0 ; // Step 13: Return 0 to indicate successful execution of the program.
}
