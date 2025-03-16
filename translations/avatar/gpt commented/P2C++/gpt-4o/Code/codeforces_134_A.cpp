#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // Use fast input
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read the number of elements
    int n;
    cin >> n;

    // Read the list of integers
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    // Calculate the sum of the list
    int x = accumulate(w.begin(), w.end(), 0);

    // Initialize a vector to store indices
    vector<int> d;

    // Iterate through each element in the list
    for (int i = 0; i < n; ++i) {
        // Check if removing the current element results in an average equal to the current element
        if ((x - w[i]) / (n - 1) == w[i]) {
            // If the condition is met, append the 1-based index to the vector
            d.push_back(i + 1);
        }
    }

    // Print the number of valid indices found
    cout << d.size() << '\n';

    // Print the valid indices as a space-separated string
    for (size_t i = 0; i < d.size(); ++i) {
        cout << d[i];
        if (i < d.size() - 1) {
            cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}

// <END-OF-CODE>
