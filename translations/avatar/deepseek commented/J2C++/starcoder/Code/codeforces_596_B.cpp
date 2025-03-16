
#include <bits/stdc++.h> // Step 1: Import the necessary C++ utility classes.
using namespace std ;
int main ( ) { // Step 2: Define the main function.
    int n ;
    cin >> n ; // Step 3: Read the size of the array from the user.
    long long arr [ n ] ;
    for ( int i = 0 ; i < n ; i ++ ) { // Step 4: Read the elements of the array from the user.
        cin >> arr [ i ] ;
    }
    long long answer = abs ( arr [ 0 ] ) ; // Step 5: Initialize a variable to store the answer.
    for ( int i = 1 ; i < n ; i ++ ) { // Step 6: Calculate the absolute difference between consecutive elements and add it to the answer.
        answer += abs ( arr [ i ] - arr [ i - 1 ] ) ;
    }
    cout << answer << endl ; // Step 7: Print the final answer.
    return 0 ;
}

