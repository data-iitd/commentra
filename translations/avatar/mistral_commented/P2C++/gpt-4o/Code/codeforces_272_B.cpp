#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// This function takes an integer as input and returns its FX value
int f(int n) {
    // Initialize a variable to store the FX value
    int fx = 1;

    // Perform bitwise operations until the number is reduced to 1
    while (n != 1) {
        // If the number is odd, increment the FX value
        if (n % 2) {
            fx += 1;
        }

        // Divide the number by 2 to reduce it further
        n /= 2;
    }

    // Return the final FX value
    return fx;
}

// This function takes a sequence as input and returns the number of pairs with common FX
int nPairsWithCommonFX(const vector<int>& sequence) {
    // Initialize an unordered map to store FX values and their corresponding values
    unordered_map<int, vector<int>> storage;

    // Iterate through each value in the sequence
    for (int value : sequence) {
        // Compute the FX value for the current value
        int fx = f(value);

        // Add the current value to the list of values for that FX
        storage[fx].push_back(value);
    }

    // Calculate the result using the formula given in the problem statement
    int result = 0;
    for (const auto& pair : storage) {
        int count = pair.second.size();
        result += count * count; // count^2
    }
    result = (result - storage.size()) / 2; // subtract the number of unique FX values and divide by 2

    // Return the result
    return result;
}

// This is the main function that takes input and calls the helper function nPairsWithCommonFX
int main() {
    // Read input from standard input
    int n;
    cin >> n; // Read the number of elements
    vector<int> sequence(n);

    // Read the sequence of integers
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    // Call the helper function with the sequence obtained from input
    int result = nPairsWithCommonFX(sequence);

    // Print the result
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
