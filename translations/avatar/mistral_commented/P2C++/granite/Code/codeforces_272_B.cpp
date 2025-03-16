
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

// This is the main function that takes input and calls the helper function nPairsWithCommonFX
int main() {
    // Read input from standard input
    std::string input;
    std::getline(std::cin, input);

    // Call the helper function with the sequence obtained from input
    int result = nPairsWithCommonFX(input);

    // Print the result
    std::cout << result << std::endl;

    return 0;
}

// This function takes a string as input and returns the number of pairs with common FX
int nPairsWithCommonFX(std::string input) {
    // Initialize an empty map to store FX values and their corresponding values
    std::map<int, std::vector<int>> storage;

    // Initialize an empty vector to store unique FX values
    std::vector<int> FXs;

    // Split the input string into individual values
    std::stringstream ss(input);
    std::string value;
    while (std::getline(ss, value,'')) {
        // Convert the value from string to integer
        int n = std::stoi(value);

        // Compute the FX value for the current value
        int fx = f(n);

        // If the FX value is not already in the map, add it along with the value
        if (storage.find(fx) == storage.end()) {
            storage[fx] = {n};
            FXs.push_back(fx);
        }
        // If the FX value is already in the map, add the current value to the list of values for that FX
        else {
            storage[fx].push_back(n);
        }
    }

    // Calculate the result using the formula given in the problem statement
    int result = (std::accumulate(FXs.begin(), FXs.end(), 0, [](int a, int b) { return a + storage[b].size() * storage[b].size(); }) - std::accumulate(FXs.begin(), FXs.end(), 0, [](int a, int b) { return a + storage[b].size(); })) / 2;

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
            fx++;
        }
        // Divide the number by 2 to reduce it further
        n /= 2;
    }

    // Return the final FX value
    return fx;
}

// Translate the above C++ code to Java and end with comment "