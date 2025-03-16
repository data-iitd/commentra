
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Create a vector of strings to hold the input values
    vector<string> input;
    // Read input from standard input (stdin) and store it in the 'input' vector
    string line;
    while (getline(cin, line)) {
        input.push_back(line);
    }

    // Initialize a 3x3 integer array to hold the input values
    int c[3][3];
    // Initialize arrays to hold differences for calculations
    int a[3], b[3];

    // Parse the input strings and populate the array 'c'
    for (int i = 0; i < 3; i++) {
        vector<string> tokens = input[i].split(" ");
        for (int j = 0; j < 3; j++) {
            c[i][j] = stoi(tokens[j]);
        }
    }

    // Calculate the first differences based on the first row of 'c'
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];

    // Calculate the differences for the second and third rows based on the first row
    a[1] = c[1][0] - c[0][0];
    a[2] = c[2][0] - c[0][0];

    // Check if the calculated differences are consistent across the matrix
    if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
        a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
        // If the conditions are met, print "Yes"
        cout << "Yes" << endl;
    } else {
        // If the conditions are not met, print "No"
        cout << "No" << endl;
    }

    return 0;
}
