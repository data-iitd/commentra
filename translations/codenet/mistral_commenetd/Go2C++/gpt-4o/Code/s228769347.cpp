// Including required headers
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read the next integer from the input
int getNextInt(istream &input) {
    int i;
    input >> i;
    return i;
}

// Main function to solve the problem
int main(int argc, char *argv[]) {
    // Initializing standard input and output file streams
    ifstream inputFile;
    ofstream outputFile;
    istream &input = (argc > 1) ? (inputFile.open(argv[1]), inputFile) : cin;
    ostream &output = (argc > 2) ? (outputFile.open(argv[2]), outputFile) : cout;

    // Read the number of elements in the array
    int n = getNextInt(input);

    // Initialize a vector to store the elements
    vector<int> ll(n);

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        ll[i] = getNextInt(input);
    }

    // Sort the vector in ascending order
    sort(ll.begin(), ll.end());

    // Initialize the answer variable to 0
    int ans = 0;

    // Iterate through all possible pairs of elements
    for (int i = 0; i < n - 2; i++) {
        // Iterate through all possible right pointers
        for (int j = i + 1; j < n - 1; j++) {
            // Initialize the left and right pointers for binary search
            int l = j + 1;
            int r = n;

            // Binary search to find the index of the element greater than the sum of the current pair
            while (l < r) {
                int m = (l + r) / 2;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            // Update the answer variable
            ans += l - (j + 1);
        }
    }

    // Write the answer to the output file
    output << ans << endl;

    // Close the files if they were opened
    if (inputFile.is_open()) inputFile.close();
    if (outputFile.is_open()) outputFile.close();

    return 0;
}

// <END-OF-CODE>
