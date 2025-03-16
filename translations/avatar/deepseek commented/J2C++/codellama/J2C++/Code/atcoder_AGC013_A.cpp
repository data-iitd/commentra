
#include <iostream> 
using namespace std ; 

int main ( ) { 
    int N ; // Step 1: Declare a variable 'N' to store the input value
    cin >> N ; // Step 2: Read the input value 'N'
    int A [ N ] ; // Step 3: Declare an array 'A' to store the elements of the array
    for ( int i = 0 ; i < N ; i ++ ) { 
        cin >> A [ i ] ; // Step 4: Read the elements of the array 'A'
    } 
    int count = 0 ; // Step 5: Declare a variable 'count' to store the number of segments
    for ( int i = 0 ; i < N ; i ++ ) { 
        if ( i == N - 1 ) 
            count ++ ; // Step 6: Check if the current index 'i' is the last index
        else if ( A [ i ] == A [ i + 1 ] ) ; // Step 7: If the current element is equal to the next element
        else if ( A [ i ] < A [ i + 1 ] ) { 
            while ( A [ i ] <= A [ i + 1 ] ) { 
                i ++ ; 
                if ( i == N - 1 ) break ; 
            } 
            count ++ ; // Step 8: Increment the counter 'count' after each segment
        } else { 
            while ( A [ i ] >= A [ i + 1 ] ) { 
                i ++ ; 
                if ( i == N - 1 ) break ; 
            } 
            count ++ ; // Step 9: Increment the counter 'count' after each segment
        } 
    } 
    cout << count << endl ; // Step 10: Print the value of the counter 'count'
    return 0 ; 
}

