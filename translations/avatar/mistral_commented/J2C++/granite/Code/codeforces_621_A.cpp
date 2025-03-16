

#include <bits/stdc++.h> // Include the necessary header files

using namespace std ; // Using the standard namespace

int main ( ) { // Defining the main function
    ios_base::sync_with_stdio ( false ) ; // Disabling synchronization between C and C++ streams
    cin.tie ( NULL ) ; // Setting the input stream to null

    int n ; // Declaring an integer variable n to store the number of elements in the list
    cin >> n ; // Reading the number of elements from the standard input

    vector < long long > list ( n ) ; // Creating a vector of long long type with the specified size to store n elements

    for ( int i = 0 ; i < n ; i ++ ) // Iterating through the input to read each element and store it in the vector
        cin >> list [ i ] ;

    vector < long long > odd ; // Creating an empty vector of long long type to store odd numbers
    long long sum = 0 ; // Initializing the sum variable to 0

    for ( long long i : list ) { // Iterating through each element in the vector
        if ( i % 2 == 0 ) // Checking if the current element is even
            sum += i ; // Adding the even number to the sum
        else
            odd.push_back ( i ) ; // Adding the odd number to the odd vector
    }

    sort ( odd.begin ( ), odd.end ( ) ) ; // Sorting the odd vector in ascending order

    for ( long long i : odd ) // Iterating through each odd number in the sorted odd vector
        sum += i ; // Adding the odd number to the sum

    if ( odd.size ( ) % 2!= 0 ) // Checking if the size of the odd vector is odd
        sum -= odd [ 0 ] ; // Subtracting the first odd number if the size is odd

    cout << sum << endl ; // Printing the final sum to the standard output

    return 0 ; // Returning 0 to indicate successful execution of the program
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!