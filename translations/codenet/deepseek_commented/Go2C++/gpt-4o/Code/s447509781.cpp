#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Input {
public:
    string NextLine() {
        string line;
        getline(cin, line);
        return line;
    }

    int NextInt() {
        return stoi(NextLine());
    }

    vector<int64_t> NextIntArray() {
        string line = NextLine();
        vector<int64_t> result;
        stringstream ss(line);
        int64_t number;
        while (ss >> number) {
            result.push_back(number);
        }
        return result;
    }
};

int main() {
    Input input;
    int n = input.NextInt(); // Read the number of elements
    vector<int64_t> s = input.NextIntArray(); // Read the array of integers
    vector<bool> u(n, false); // Initialize a boolean array to track visited positions
    int64_t m = 0, f = 0;

    // Iterate over possible values of c to find the maximum sum
    for (int c = 1; c < n - 1; c++) {
        f = 0;
        // Iterate over possible multiples of c
        for (int k = 0; c < n - 1 - k * c; k++) {
            u[k * c] = true; // Mark the position as visited
            if (u[n - 1 - k * c]) break; // If the position is already visited, break the loop
            f += s[n - 1 - k * c] + s[k * c]; // Add the values at the current positions
            if (m < f) m = f; // Update the maximum sum if the current sum is greater
        }
        // Reset the boolean array for the next value of c
        for (int k = 0; k * c < n - 1; k++) {
            u[k * c] = false;
        }
    }
    cout << m << endl; // Print the maximum sum found
    return 0;
}

// <END-OF-CODE>
