#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform the main logic of the program
void main() {

    // Initialize variables n and m with the given input
    int n, m;
    cin >> n >> m;

    // Initialize vectors round_complexity and george_complexity
    // with the given input
    vector<int> round_complexity(n);
    vector<int> george_complexity(m);

    // Read the round complexities
    for (int i = 0; i < n; ++i) {
        cin >> round_complexity[i];
    }

    // Read the George's complexities
    for (int j = 0; j < m; ++j) {
        cin >> george_complexity[j];
    }

    // Initialize variables i and j to 0
    int i = 0, j = 0;

    // Start the while loop that compares the complexity of each
    // round with George's complexity and moves the pointers accordingly
    while (i < n && j < m) {

        // Increment i if the complexity of the current round is
        // less than or equal to George's complexity at the current j
        if (round_complexity[i] <= george_complexity[j]) {
            ++i;
        }

        // Increment j
        ++j;
    }

    // Print the final answer
    cout << n - i << endl;
}

