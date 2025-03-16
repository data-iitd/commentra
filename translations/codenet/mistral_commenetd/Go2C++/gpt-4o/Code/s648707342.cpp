#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an arm
struct Arm {
    int l, r;
};

// Function to read an integer from standard input
int scanInt() {
    int x;
    cin >> x; // Read the integer
    return x; // Return the integer
}

// Main function
int main() {
    // Read the number of arms, n
    int n = scanInt();

    // Initialize a vector of arm structures
    vector<Arm> arms(n);

    // Read and initialize each arm structure in the vector
    for (int i = 0; i < n; i++) {
        int x = scanInt();
        int l = scanInt();

        // Initialize the left and right fields of the arm structure
        arms[i].l = x - l;
        arms[i].r = x + l;
    }

    // Sort the vector based on the right field of the arm structures
    sort(arms.begin(), arms.end(), [](const Arm &a, const Arm &b) {
        return a.r < b.r;
    });

    // Initialize answer variable, ans, and right variable, r
    int ans = 1;
    int r = arms[0].r;

    // Iterate through the vector and update the answer and right variable accordingly
    for (int i = 1; i < n; i++) {
        if (arms[i].l >= r) { // Check if the left end of the current arm is greater than or equal to the right end of the previous arm
            ans++; // Increment the answer if it is
            r = arms[i].r; // Update the right variable with the right end of the current arm
        }
    }

    // Print the answer
    cout << ans << endl;

    // End of code
    return 0;
}
// <END-OF-CODE>
