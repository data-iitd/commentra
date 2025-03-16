#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, count;
    cin >> n >> count;
    printIsland(n, count);
}

// Method to print the island pattern based on the given size and count of 'L' characters
void printIsland(int n, int count) {
    int a = (n + 1) / 2; // Calculating the number of 'L' characters in the first diagonal
    int b = n / 2; // Calculating the number of 'L' characters in the second diagonal
    int max = a * a + b * b; // Calculating the maximum possible number of 'L' characters

    // Checking if the requested count exceeds the maximum possible 'L' characters
    if (count > max) {
        cout << "NO" << endl; // Printing "NO" if count is too high
        return; // Returning from the method as further execution is unnecessary
    }

    cout << "YES" << endl; // Printing "YES" as the count is within the allowed range

    // Building the island grid
    for (int i = 0; i < n; i++) {
        string s = ""; // Creating a string to build the row
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0 && count > 0) { // Checking if the position should be 'L'
                s += 'L'; // Appending 'L' to the string
                count--; // Decrementing the count of 'L' characters
            } else {
                s += 'S'; // Appending 'S' to the string
            }
        }
        cout << s << endl; // Printing the constructed row
    }
}

