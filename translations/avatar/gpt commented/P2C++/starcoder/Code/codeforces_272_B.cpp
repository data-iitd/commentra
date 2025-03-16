#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // Read input from the user (not stored, just consumed)
    cin.ignore();
    // Process the input sequence and return the number of pairs with common factors
    return nPairsWithCommonFX(vector<int>(istream_iterator<int>(cin), istream_iterator<int>()));
}

int nPairsWithCommonFX(vector<int> sequence) {
    // Initialize a dictionary to store values based on their computed factor
    map<int, vector<int>> storage;
    // List to keep track of unique factors
    vector<int> FXs;
    
    // Iterate through each value in the input sequence
    for (int value : sequence) {
        // Compute the factor for the current value
        int y = f(value);
        // If the factor is not already in storage, add it
        if (storage.find(y) == storage.end()) {
            storage[y] = {value};  // Store the value under its factor
            FXs.push_back(y);       // Keep track of the unique factor
        } else {
            // If the factor already exists, append the value to the existing list
            storage[y].push_back(value);
        }
    }
    
    // Calculate the total number of pairs with common factors
    // The formula counts pairs and subtracts the number of single occurrences
    return (accumulate(FXs.begin(), FXs.end(), 0, [](int x, int y) { return x + y; }) - accumulate(storage.begin(), storage.end(), 0, [](int x, pair<int, vector<int>> y) { return x + y.second.size(); })) / 2;
}

int f(int n) {
    // Initialize the factor count
    int y = 1;
    // Loop until n is reduced to 1
    while (n!= 1) {
        // If n is odd, increment the factor count
        if (n % 2) {
            y += 1;
        }
        // Divide n by 2 to reduce it
        n /= 2;
    }
    // Return the total count of factors
    return y;
}

