

#include <iostream> // Include the C++ standard input/output stream objects
#include <vector> // Include the C++ standard vector container
#include <algorithm> // Include the C++ standard algorithm library

using namespace std ; // Define the current namespace

int main ( ) { // Define the main function as the entry point of the program
    int N ; // Declare an integer variable N to store the size of the input array
    cin >> N ; // Read the first integer N from the standard input and store it in the variable N

    vector < int > L ( N ) ; // Create a vector of integers with a capacity equal to N

    for ( int i = 0 ; i < N ; i ++ ) { // Use a for loop to read N integers from the standard input and add them to the vector
        cin >> L [ i ] ;
    }

    sort ( L.begin ( ), L.end ( ) ) ; // Sort the vector using the sort() method from the algorithm library

    int count = 0 ; // Initialize an integer variable count to 0

    for ( int i = 0 ; i < N ; i ++ ) { // Use a nested for loop to iterate through all pairs of adjacent elements in the sorted vector
        for ( int j = i + 1 ; j < N ; j ++ ) {
            int a = L [ i ] ; // Get the first integer of the pair
            int b = L [ j ] ; // Get the second integer of the pair
            int res = find ( L, j + 1, a + b ) ; // Call the find() function to find the number of elements greater than the sum of the pair
            count = count + res ; // Add the result of the find() function to the variable count
        }
    }

    cout << count << endl ; // Print the final value of the variable count to the standard output stream

    return 0 ; // Return 0 to indicate successful program execution
}

int find ( vector < int > & li, int from, int target ) { // Define the find() function that takes three arguments: a reference to a vector of integers, an index from where to start the search, and an integer target
    int low = from ; // Initialize the lower bound of the binary search
    int upp = li.size ( ) - 1 ; // Initialize the upper bound of the binary search
    int mid = 0 ; // Initialize an integer variable mid to store the middle index of the binary search

    if ( upp - low < 0 ) { // Check if the vector is empty or the target integer is less than the first element
        return 0 ;
    } else if ( li [ from ] >= target ) { // Check if the target integer is greater than or equal to the first element
        return 0 ;
    } else if ( li [ upp ] < target ) { // Check if the target integer is less than the last element
        return upp - low + 1 ;
    }

    while ( upp - low > 1 ) { // Perform the binary search
        mid = ( upp - low + 1 ) % 2 == 0? ( low + upp ) / 2 + 1 : ( low + upp ) / 2 ; // Calculate the middle index of the binary search

        if ( li [ mid ] >= target ) { // If the middle element is greater than or equal to the target, update the upper bound of the search
            upp = mid ;
        } else { // If the middle element is less than the target, update the lower bound of the search
            low = mid ;
        }
    }

    return low - from + 1 ; // Return the index of the middle element minus the starting index plus one
}

