#include <iostream>
#include <vector>

using namespace std;

// Function to perform the main logic of the program
void main() {

    // Initialize variables n and m with the given input
    int n, m;
    cin >> n >> m;

    // Initialize lists round_complexity and george_complexity
    // with the given input
    vector<int> round_complexity(n);
    vector<int> george_complexity(m);
    for (int i = 0; i < n; i++) {
        cin >> round_complexity[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> george_complexity[i];
    }

    // Initialize variables i and j to 0
    int i = 0, j = 0;

    // Start the while loop that compares the complexity of each
    // round with George's complexity and moves the pointers accordingly
    while (i < n && j < m) {

        // Increment i if the complexity of the current round is
        // less than or equal to George's complexity at the current j
        i += 1 if (round_complexity[i] <= george_complexity[j]) else 0;

        // Increment j
        j += 1;
    }

    // Print the final answer
    cout << n - i << endl;
}

