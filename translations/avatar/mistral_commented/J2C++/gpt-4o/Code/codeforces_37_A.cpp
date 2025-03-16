#include <iostream> // Include iostream for input and output
#include <unordered_map> // Include unordered_map for using hash maps
#include <vector> // Include vector for using dynamic arrays
#include <algorithm> // Include algorithm for using max function

using namespace std; // Use the standard namespace

int main() {
    int n; // Variable to store the number of integers
    cin >> n; // Read the number of integers from standard input

    // Initialize an empty unordered_map with int keys and int values
    unordered_map<int, int> map;

    // Iterate through the given number of integers and add each integer to the unordered_map with its count
    for (int i = 0; i < n; i++) {
        int val; // Variable to store the current integer
        cin >> val; // Read the next integer from standard input
        map[val]++; // Increment the count of the integer in the unordered_map
    }

    // Initialize maximum value variable
    int maxCount = 0; // Variable to store the maximum count
    for (const auto& entry : map) {
        // Update the maximum count if the current entry's value is greater than the maximum count
        maxCount = max(maxCount, entry.second);
    }

    // Print the maximum count and the size of the unordered_map
    cout << maxCount << " " << map.size() << endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
