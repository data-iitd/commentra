
#include <iostream>
#include <vector>

using namespace std;

int main ( ) {
    // Initialize an empty vector `L`
    vector < int > L;

    // Read the first input, which is the number of elements to add to the list
    int n;
    cin >> n;

    // Use a for loop to iterate through each integer in the input
    for ( int i = 0; i < n; i++ ) {
        // Add `r` elements to the vector `L` with the value `r`
        L.insert ( L.end ( ), r, r );
        // Increment the value of `r` by 1 to prepare for the next iteration
        r++;
    }

    // Read the second input, which represents the indices of the elements to print from the list
    int m;
    cin >> m;

    // Use another for loop to iterate through each integer in the input
    for ( int j = 0; j < m; j++ ) {
        // Print the element at the given index using the index as an offset from the beginning of the list
        cout << L [ j ] << endl;
    }

    return 0;
}

