#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 

using namespace std ; 

int main ( ) { 
    int n ; // Declare the size of the grid
    int square ; // Declare the total number of elements
    
    vector < int > odd ; // Declare a vector to store odd numbers
    vector < int > even ; // Declare a vector to store even numbers
    
    cin >> n ; // Read the size of the grid
    square = n * n ; // Calculate the total number of elements
    
    // Separating numbers into odd and even vectors
    for ( int i = 1 ; i <= square ; i ++ ) { 
        if ( i % 2 == 0 ) { 
            even.push_back ( i ) ; // Add even numbers to the even vector
        } else { 
            odd.push_back ( i ) ; // Add odd numbers to the odd vector
        } 
    }
    
    int loop = square / n ; // Calculate the number of rows/columns
    int div = loop / 2 ; // Calculate half the number of elements in each row/column
    
    // Nested loops to generate the pattern
    for ( int i = 1 ; i <= loop ; i ++ ) { 
        for ( int j = 0 ; j < div ; j ++ ) { 
            if ( i % 2 == 1 ) { 
                cout << odd.at ( 0 ) << " " << even.at ( even.size ( ) - 1 ) << " " ; // Print odd and even numbers in reverse order for odd rows
                odd.erase ( odd.begin ( ) ) ; // Remove the first element from the odd vector
                even.erase ( even.end ( ) - 1 ) ; // Remove the last element from the even vector
            } else { 
                cout << even.at ( 0 ) << " " << odd.at ( odd.size ( ) - 1 ) << " " ; // Print even and odd numbers in reverse order for even rows
                even.erase ( even.begin ( ) ) ; // Remove the first element from the even vector
                odd.erase ( odd.end ( ) - 1 ) ; // Remove the last element from the odd vector
            } 
        } 
        cout << endl ; // Move to the next line after each row
    } 
    
    return 0 ; // Return 0 to indicate successful execution
} 

