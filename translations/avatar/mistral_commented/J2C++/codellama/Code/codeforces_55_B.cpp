
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std ; // Using the standard namespace

long min ; // Initializing the minimum value to LONG_MAX

void util ( vector < long > arr , string [ ] ops , int idx ) { // Starting the util method
    if ( idx == 3 ) { // Checking if the index of the operator is equal to 3 (the last operator)
        min = min < arr [ 0 ] ? min : arr [ 0 ] ; // Updating the minimum value with the first number in the ArrayList
        return ; // Exiting the method
    }

    for ( int i = 0 ; i < arr.size ( ) ; i ++ ) { // Iterating through the ArrayList to find two numbers for the current operator
        for ( int j = i + 1 ; j < arr.size ( ) ; j ++ ) {
            vector < long > a ( ) ; // Creating a new ArrayList to store the result of the current operation

            for ( int k = 0 ; k < arr.size ( ) ; k ++ ) { // Iterating through the ArrayList to exclude the current and previous numbers
                if ( k != j && k != i ) {
                    a.push_back ( arr [ k ] ) ; // Adding the excluded number to the new ArrayList
                }
            }

            long res ; // Initializing the result variable

            if ( idx < 3 && ops [ idx ] == "+" ) { // Checking if the current operator is '+'
                res = arr [ i ] + arr [ j ] ; // Performing the addition operation
            } else { // Else, the current operator is '*'
                res = arr [ i ] * arr [ j ] ; // Performing the multiplication operation
            }

            a.push_back ( res ) ; // Adding the result to the new ArrayList
            util ( a , ops , idx + 1 ) ; // Recursively calling the util method with the new ArrayList, the array of operators, and the index of the next operator
        }
    }
}

int main ( ) { // Starting the main method
    vector < long > arr ( ) ; // Creating an empty ArrayList of long type to store the input numbers
    string [ ] ops = new string [ 3 ] ; // Creating an array of String type to store the operators
    long num ; // Initializing the number variable

    for ( int i = 0 ; i < 4 ; i ++ ) { // Reading 4 numbers from the standard input and storing them in the ArrayList
        cin >> num ;
        arr.push_back ( num ) ;
    }

    for ( int i = 0 ; i < 3 ; i ++ ) { // Reading 3 operators from the standard input and storing them in the array
        cin >> ops [ i ] ;
    }

    min = LONG_MAX ; // Setting the initial value of min to LONG_MAX
    util ( arr , ops , 0 ) ; // Calling the util method with the ArrayList, the array of operators, and the index of the first operator

    cout << min << endl ; // Printing the minimum value found during the execution

    return 0 ; // Exiting the main method
}

