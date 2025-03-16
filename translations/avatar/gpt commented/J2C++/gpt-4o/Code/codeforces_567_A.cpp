#include <iostream> // Including iostream for input and output
#include <vector>   // Including vector for dynamic array
#include <algorithm> // Including algorithm for std::max and std::min

using namespace std;

int main() {
    // Creating a variable to hold the number of elements to be inputted
    int a;
    cin >> a; // Reading the number of elements

    // Initializing a vector to hold the input integers
    vector<int> ar(a);

    // Loop to read integers into the vector
    for (int i = 0; i < ar.size(); i++) {
        cin >> ar[i]; // Reading each integer into the vector
    }

    // Variables to hold the maximum and minimum differences
    int maxDiff = 0, minDiff = 0;

    // Loop to calculate and print the min and max differences for each element
    for (int i = 0; i < ar.size(); i++) {
        // Calculating the maximum difference from the first and last elements
        maxDiff = max(ar[i] - ar[0], ar[ar.size() - 1] - ar[i]);

        // Calculating the minimum difference based on the position of the current element
        if (i == 0) {
            // If it's the first element, compare with the second element
            minDiff = ar[i + 1] - ar[i];
        } else if (i == ar.size() - 1) {
            // If it's the last element, compare with the second last element
            minDiff = ar[i] - ar[i - 1];
        } else {
            // For middle elements, compare with both neighbors
            minDiff = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]);
        }

        // Printing the minimum and maximum differences for the current element
        cout << minDiff << " " << maxDiff << endl;
    }

    return 0; // Indicating successful completion
}

// <END-OF-CODE>
