#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Function to process the input and produce output
int run(istream &input, ostream &output) {
    int N;
    input >> N; // Read the number of elements
    string S;
    input >> S; // Read the string of colors

    // Handle case where there are no elements
    if (N == 0) {
        return 0;
    }

    // If there are fewer than 4 elements, output 0
    if (N < 4) {
        output << 0 << endl;
        return 0;
    }

    // Count occurrences of each color
    int nr = 0, nb = 0, ng = 0;
    for (char c : S) {
        if (c == 'R') {
            nr++;
        } else if (c == 'B') {
            nb++;
        } else if (c == 'G') {
            ng++;
        }
    }

    int same = 0; // Counter for same color combinations

    // Iterate through possible combinations of indices
    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = 1 * a;
        int k = 2 * a;
        if (k >= N) {
            break; // Exit if index exceeds string length
        }
        while (k < N) {
            // Check if the colors at the indices are different
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++; // Increment same color combination counter
            }
            i++; // Move to the next index
            j++;
            k++;
        }
    }

    // Calculate total combinations of different colors
    int tot = nr * nb * ng;

    // Output the result by subtracting same combinations from total
    output << tot - same << endl;

    return 0; // Return success
}

// Main function to execute the program
int main() {
    return run(cin, cout); // Run the program and exit
}

// <END-OF-CODE>
