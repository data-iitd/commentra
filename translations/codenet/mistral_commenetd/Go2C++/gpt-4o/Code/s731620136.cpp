#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to read an integer from input
int nextInt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    int N = nextInt(); // Read the first integer from input

    if (N < 4) { // Check if N is less than 4
        cout << 0 << endl; // Print 0 if N is less than 4
        return 0; // Return 0
    }

    string S;
    cin >> S; // Read the string S

    int nr = 0, nb = 0, ng = 0; // Declare and initialize variables for red, blue, and green balls

    for (char c : S) { // Iterate through each character in the string S
        if (c == 'R') {
            nr++; // Increment the nr counter
        } else if (c == 'B') {
            nb++; // Increment the nb counter
        } else if (c == 'G') {
            ng++; // Increment the ng counter
        }
    }

    int same = 0; // Initialize a counter for the number of same-colored groups of three balls

    // Outer loop to iterate through each index a from 1 to N-1
    for (int a = 1; a < N; a++) {
        int i = 0; // Initialize index i to 0
        int j = 1 * a; // Initialize index j to a multiplied by 1
        int k = 2 * a; // Initialize index k to a multiplied by 2

        // Inner loop to iterate through each index k from a*2 to N-1
        while (k < N) {
            // Check if the balls at indices i, j, and k have different colors
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++; // If so, increment the same counter
            }

            // Update indices
            i += 1; // Increment index i
            j += 1; // Increment index j
            k += 1; // Increment index k
        }
    }

    int tot = nr * nb * ng; // Calculate the total number of balls

    cout << tot - same << endl; // Print the result, which is the total number of balls minus the number of same-colored groups of three balls

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
