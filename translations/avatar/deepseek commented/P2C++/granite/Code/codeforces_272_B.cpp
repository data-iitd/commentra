
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Take input from the user
    int n;
    cin >> n;
    // Process the input and call nPairsWithCommonFX with the processed input
    return nPairsWithCommonFX(vector<int>(istream_iterator<int>(cin), {}));
}

int nPairsWithCommonFX(vector<int> sequence) {
    // Initialize a dictionary to store values grouped by their computed property
    unordered_map<int, vector<int>> storage;
    // List to store the computed property values
    vector<int> FXs;
    for (int value : sequence) {
        // Compute the property for the current value
        int y = f(value);
        // If the property is not already in storage, add it with the current value
        if (storage.find(y) == storage.end()) {
            storage[y] = {value};
            FXs.push_back(y);
        } else {
            // Otherwise, append the current value to the list of values for this property
            storage[y].push_back(value);
        }
    }
    // Calculate the number of pairs with common factor greater than 1
    int result = 0;
    for (int y : FXs) {
        result += storage[y].size() * storage[y].size();
    }
    return (result - FXs.size()) / 2;
}

int f(int n) {
    // Initialize y to 1, which will be the result for the property of n
    int y = 1;
    while (n!= 1) {
        if (n % 2) {
            y += 1;
        }
        n /= 2;
    }
    return y;
}

int main() {
    // Print the result of the main function
    cout << nPairsWithCommonFX({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;
    return 0;
}

