#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int f(int n) {
    int y = 1; // Initialize y to 1
    while (n != 1) {
        if (n % 2) {
            y += 1; // Increment y if n is odd
        }
        n /= 2; // Divide n by 2
    }
    return y; // Return the computed property
}

int nPairsWithCommonFX(const vector<int>& sequence) {
    unordered_map<int, vector<int>> storage; // Dictionary to store values grouped by their computed property
    vector<int> FXs; // List to store the computed property values

    for (int value : sequence) {
        int y = f(value); // Compute the property for the current value
        if (storage.find(y) == storage.end()) {
            storage[y] = {value}; // Add new property with the current value
            FXs.push_back(y); // Store the property
        } else {
            storage[y].push_back(value); // Append the current value to the existing property
        }
    }

    // Calculate the number of pairs with common factor greater than 1
    int totalPairs = 0;
    for (int y : FXs) {
        int count = storage[y].size();
        totalPairs += count * count; // Count pairs for this property
    }
    int singleCount = 0;
    for (int y : FXs) {
        singleCount += storage[y].size(); // Count single occurrences
    }
    return (totalPairs - singleCount) / 2; // Return the final count of pairs
}

int main() {
    int n;
    cin >> n; // Take input from the user
    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i]; // Read the sequence of numbers
    }
    cout << nPairsWithCommonFX(sequence) << endl; // Print the result
    return 0;
}

// <END-OF-CODE>
