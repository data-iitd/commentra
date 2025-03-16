#include <iostream> // Including iostream for input and output
#include <vector>   // Including vector for dynamic array
#include <algorithm> // Including algorithm for std::max and std::min

using namespace std;

int main() {
    int a; // Variable to hold the size of the array
    cin >> a; // Reading the size of the array from the user
    vector<int> ar(a); // Initializing the vector with the size read from the user
    int max = 0, min = 0; // Initializing max and min to 0

    // Filling the vector with integers read from the user
    for (int i = 0; i < ar.size(); i++) {
        cin >> ar[i];
    }

    // Calculating the minimum and maximum differences between consecutive elements of the array
    for (int i = 0; i < ar.size(); i++) {
        max = std::max(ar[i] - ar[0], ar[ar.size() - 1] - ar[i]); // Calculating the maximum difference
        if (i == 0) {
            min = ar[i + 1] - ar[i]; // Calculating the minimum difference for the first element
        } else if (i == ar.size() - 1) {
            min = ar[i] - ar[i - 1]; // Calculating the minimum difference for the last element
        } else {
            min = std::min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]); // Calculating the minimum difference for other elements
        }
        cout << min << " " << max << endl; // Displaying the minimum and maximum differences
    }

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
