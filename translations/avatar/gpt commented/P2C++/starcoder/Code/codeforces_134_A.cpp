#include <bits/stdc++.h>

using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the list of integers
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    // Calculate the sum of the list
    int x = accumulate(w.begin(), w.end(), 0);

    // Initialize an empty list to store indices
    vector<int> d;

    // Iterate through each element in the list
    for (int i = 0; i < n; i++) {
        // Check if removing the current element results in an average equal to the current element
        if ((x - w[i]) / (n - 1) == w[i]) {
            // If the condition is met, append the 1-based index to the list
            d.push_back(i + 1);
        }
    }

    // Print the number of valid indices found
    cout << d.size() << endl;

    // Print the valid indices as a space-separated string
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }

    return 0;
}

