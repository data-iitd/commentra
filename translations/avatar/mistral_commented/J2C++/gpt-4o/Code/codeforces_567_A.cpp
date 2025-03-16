#include <iostream> // Including iostream for input and output
#include <vector>   // Including vector for dynamic array
#include <algorithm> // Including algorithm for max and min functions

using namespace std;

int main() {
    int a;
    cin >> a; // Asking user for the size of the array

    vector<int> ar(a); // Initializing a vector of size 'a'

    // Reading array elements from user input
    for (int i = 0; i < ar.size(); i++) {
        cin >> ar[i]; // Reading an integer value from user input and storing it in the vector
    }

    // Initializing variables for storing maximum and minimum differences
    int maxDiff = 0, minDiff = 0;

    // Finding maximum and minimum differences between consecutive elements in the array
    for (int i = 0; i < ar.size(); i++) {
        // Finding maximum difference between current element and first element
        maxDiff = max(ar[i] - ar[0], ar[ar.size() - 1] - ar[i]);

        // Finding minimum difference between current element and previous element
        if (i == 0) {
            minDiff = ar[i + 1] - ar[i]; // For the first element, minimum difference is between current and next element
        } else if (i == ar.size() - 1) {
            minDiff = ar[i] - ar[i - 1]; // For the last element, minimum difference is between current and previous element
        } else {
            minDiff = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]); // For other elements, minimum difference is between current and previous or next element, whichever is smaller
        }

        // Printing minimum and maximum differences for each pair of consecutive elements
        cout << minDiff << " " << maxDiff << endl;
    }

    return 0; // Indicating successful completion
}

// <END-OF-CODE>
