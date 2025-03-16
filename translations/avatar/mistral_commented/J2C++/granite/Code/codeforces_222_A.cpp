
#include <iostream> // Including the standard input/output library

using namespace std ; // Using the standard namespace

int main ( ) { // Defining the main function
    int n, k, l = 0, c = 1 ; // Declaring and initializing the variables n, k, l, and c with values 0 and 1 respectively

    cin >> n >> k ; // Reading the first two integers from the input and assigning them to variables n and k respectively

    for ( int i = 0 ; i < n ; i ++ ) { // Starting a for loop that iterates n times
        int a ; // Declaring a new integer variable a

        cin >> a ; // Reading the next integer from the input and assigning it to variable a

        if ( a == l ) c += 1 ; // If the current integer is equal to the previous one, increment the counter c by 1
        else c = 1 ; // Otherwise, reset the counter c to 1

        l = a ; // Assigning the current integer to the previous integer variable l
    }

    if ( c + k > n ) { // Checking if the sum of counter c and integer k is greater than the total number of integers n
        cout << n - c ; // If true, print the difference between n and c
    } else {
        cout << - 1 ; // If false, print -1
    }

    return 0 ; // Returning 0 to indicate successful execution of the program
}
