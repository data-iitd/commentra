#include <iostream> // For input and output operations
#include <vector>   // For using vectors
#include <algorithm> // For sorting operations

using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements
    vector<int> ar(3 * n); // Create a vector of size 3*n
    for (int i = 0; i < 3 * n; i++) {
        cin >> ar[i]; // Populate the vector with integers from input
    }
    sort(ar.begin(), ar.end()); // Sort the vector
    int sum = 0; // Initialize sum to 0
    for (int i = 0; i < n; i++) {
        sum += ar[3 * n - (i + 1) * 2]; // Calculate the sum of the last n elements, skipping every second element
    }
    cout << sum << endl; // Print the sum
    return 0;
}

// <END-OF-CODE>
