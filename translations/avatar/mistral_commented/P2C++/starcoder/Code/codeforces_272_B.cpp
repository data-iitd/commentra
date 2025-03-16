#include <iostream>
#include <vector>
#include <map>

using namespace std;

// This function takes a sequence as input and returns the number of pairs with common FX
int nPairsWithCommonFX(vector<int> sequence) {
    // Initialize an empty dictionary to store FX values and their corresponding values
    map<int, vector<int>> storage;

    // Initialize an empty list to store unique FX values
    vector<int> FXs;

    // Iterate through each value in the sequence
    for (int value : sequence) {
        // Compute the FX value for the current value
        int fx = f(value);

        // If the FX value is not already in the dictionary, add it along with the value
        if (storage.find(fx) == storage.end()) {
            storage[fx] = {value};
            FXs.push_back(fx);
        }

        // If the FX value is already in the dictionary, add the current value to the list of values for that FX
        else {
            storage[fx].push_back(value);
        }
    }

    // Calculate the result using the formula given in the problem statement
    int result = (accumulate(FXs.begin(), FXs.end(), 0, [](int a, int b) { return a + b; }) * accumulate(FXs.begin(), FXs.end(), 0, [](int a, int b) { return a + b; }) - accumulate(FXs.begin(), FXs.end(), 0)) / 2;

    // Return the result
    return result;
}

// This function takes an integer as input and returns its FX value
int f(int n) {
    // Initialize a variable to store the FX value
    int fx = 1;

    // Perform bitwise operations until the number is reduced to 1
    while (n!= 1) {
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

// Run the main function if the script is executed directly
int main() {
    // Read input from standard input
    cin.ignore();

    // Call the helper function with the sequence obtained from input
    int result = nPairsWithCommonFX(vector<int>(istream_iterator<int>(cin), {}));

    // Print the result
    cout << result << endl;

    // Return from the main function
    return 0;
}

