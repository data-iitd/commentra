#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

class Input {
public:
    // Function to read a line from standard input
    string NextLine() {
        string line;
        getline(cin, line);
        return line;
    }

    // Function to read an integer from input
    int NextInt() {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
        return n;
    }

    // Function to read a line of integers and return them as a vector
    vector<long long> NextIntArray() {
        string line = NextLine();
        stringstream ss(line);
        long long number;
        vector<long long> result;

        while (ss >> number) {
            result.push_back(number);
        }
        return result;
    }
};

int main() {
    Input input;

    // Read the number of elements and the array of integers from input
    int n = input.NextInt();
    vector<long long> s = input.NextIntArray();

    // Create a boolean vector to track used indices
    vector<bool> u(n, false);

    // Initialize variables to store the maximum sum and a temporary sum
    long long m = 0, f = 0;

    // Iterate through possible values of c from 1 to n-2
    for (int c = 1; c < n - 1; c++) {
        f = 0; // Reset the temporary sum for each c

        // Iterate to find pairs of indices based on the current value of c
        for (int k = 0; c < n - 1 - k * c; k++) {
            u[k * c] = true; // Mark the current index as used

            // Break if the corresponding index is already used
            if (u[n - 1 - k * c]) break;

            // Calculate the sum of the elements at the current indices
            f += s[n - 1 - k * c] + s[k * c];

            // Update the maximum sum if the current sum is greater
            if (m < f) m = f;
        }

        // Reset the used indices for the next iteration of c
        for (int k = 0; k * c < n - 1; k++) {
            u[k * c] = false;
        }
    }

    // Print the maximum sum found
    cout << m << endl;

    return 0;
}

// <END-OF-CODE>
