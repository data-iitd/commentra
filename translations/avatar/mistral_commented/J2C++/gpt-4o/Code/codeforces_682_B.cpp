#include <iostream>  // Importing necessary classes for input and output
#include <vector>    // Importing necessary classes for vector
#include <algorithm> // Importing necessary classes for sort
#include <iterator>  // Importing necessary classes for iterators

using namespace std;

int main() {
    // Creating a variable to store the number of elements in the list
    int n;
    cin >> n; // Reading the number of elements from the input

    // Creating a vector to store the elements
    vector<int> list(n);

    // Reading 'n' elements from the input and adding them to the vector
    for (int i = 0; i < n; i++) {
        cin >> list[i]; // Reading an integer from the input and adding it to the vector
    }

    // Sorting the vector in ascending order
    sort(list.begin(), list.end());

    // Initializing a variable 'c' to keep track of the number of distinct elements
    int c = 1;

    // Iterating through the vector to find the number of distinct elements
    for (int i = 0; i < n; i++) {
        // If the current element is greater than or equal to the current count 'c', increment the count
        if (list[i] >= c) {
            c++;
        }
    }

    // Writing the result to the output
    cout << c << endl;

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
