#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of groups of three integers
    int n;
    cin >> n;

    // Initialize a vector to hold 3*n integers
    vector<int> ar(3 * n);

    // Populate the vector with integers from input
    for (int i = 0; i < 3 * n; i++) {
        cin >> ar[i];
    }

    // Sort the vector of integers in ascending order
    sort(ar.begin(), ar.end());

    // Initialize a variable to hold the sum of selected integers
    int sum = 0;

    // Calculate the sum of the second largest integer from each group of three
    for (int i = 0; i < n; i++) {
        sum += ar[3 * n - (i + 1) * 2]; // Select the second largest integer from the sorted vector
    }

    // Print the final computed sum
    cout << sum << endl;

    return 0;
}

// <END-OF-CODE>
