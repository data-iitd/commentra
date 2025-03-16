#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using dynamic arrays
#include <algorithm> // Including the algorithm library for sorting

using namespace std; // Using the standard namespace

int main() {
    int n; // Variable to store the number of elements in the array
    cin >> n; // Reading the number of elements from user input
    vector<int> a(n); // Creating a vector of size n

    // Initializing the vector with user input
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Reading each element into the vector
    }

    // Sorting the vector in ascending order
    sort(a.begin(), a.end());

    // Checking if there is any pair of adjacent elements that satisfy the condition
    for (int i = 0; i < a.size() - 1; i++) {
        // Checking if the next element is less than twice the current element and they are not the same
        if (a[i + 1] < a[i] * 2 && a[i] != a[i + 1]) {
            cout << "YES" << endl; // Printing "YES" if a pair is found
            return 0; // Exiting the program if a pair is found
        }
    }

    // If no pair is found, printing "NO"
    cout << "NO" << endl;
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
