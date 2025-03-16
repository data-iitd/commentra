

#include <iostream> // Include the iostream library for input/output operations
#include <map> // Include the map library for using associative arrays
#include <algorithm> // Include the algorithm library for using functions like max_element

using namespace std; // Use the standard namespace for simplifying code

int main() {
    int n; // Declare an integer variable n to store the number of integers
    cin >> n; // Read the number of integers from the standard input

    // Initialize an empty map with Integer keys and Integer values
    map<int, int> map;

    // Iterate through the given number of integers and add each integer to the map with its count
    for (int i = 0; i < n; i++) {
        int val; // Declare an integer variable val to store the current integer
        cin >> val; // Read the next integer from the standard input
        map[val]++; // Add the integer to the map with its count or 1 if it's the first occurrence
    }

    // Initialize maximum value variable
    int max = *max_element(map.begin(), map.end()); // Find the maximum value in the map using the max_element function from the algorithm library

    // Print the maximum value and the size of the map
    cout << max << " " << map.size() << endl; // Print the maximum value and the size of the map

    return 0; // Return 0 to indicate successful execution of the program
}

These comments should provide a clear understanding of the code's functionality and logic.