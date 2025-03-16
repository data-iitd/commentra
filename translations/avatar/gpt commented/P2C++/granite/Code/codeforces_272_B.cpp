
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Read input from the user (not stored, just consumed)
    cin.ignore();
    // Process the input sequence and return the number of pairs with common factors
    return nPairsWithCommonFX(transform(istream_iterator<int>(cin), {}, [](int x) { return x; }));
}

int nPairsWithCommonFX(const vector<int>& sequence) {
    // Initialize a dictionary to store values based on their computed factor
    unordered_map<int, vector<int>> storage;
    // List to keep track of unique factors
    vector<int> FXs;

    // Iterate through each value in the input sequence
    for (int value : sequence) {
        // Compute the factor for the current value
        int y = f(value);
        // If the factor is not already in storage, add it
        if (storage.find(y) == storage.end()) {
            storage[y] = {value};  // Store the value under its factor
            FXs.push_back(y);         // Keep track of the unique factor
        } else {
            // If the factor already exists, append the value to the existing list
            storage[y].push_back(value);
        }
    }

    // Calculate the total number of pairs with common factors
    // The formula counts pairs and subtracts the number of single occurrences
    int result = 0;
    for (int y : FXs) {
        result += storage[y].size() * storage[y].size();
    }
    result -= FXs.size();
    return result / 2;
}

int f(int n) {
    // Initialize the factor count
    int y = 1;
    // Loop until n is reduced to 1
    while (n!= 1) {
        // If n is odd, increment the factor count
        if (n % 2) {
            y++;
        }
        // Divide n by 2 to reduce it
        n /= 2;
    }
    // Return the total count of factors
    return y;
}

int main() {
    // Execute the main function and print the result
    cout << nPairsWithCommonFX({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;  // Output: 45
    return 0;
}

