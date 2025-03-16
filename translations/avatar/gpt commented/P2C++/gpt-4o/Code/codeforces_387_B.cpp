#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of rounds (n) and the number of George's complexities (m)
    int n, m;
    cin >> n >> m;
    
    // Read the complexities for each round into a vector
    vector<int> round_complexity(n);
    for (int i = 0; i < n; ++i) {
        cin >> round_complexity[i];
    }
    
    // Read George's complexities into another vector
    vector<int> george_complexity(m);
    for (int j = 0; j < m; ++j) {
        cin >> george_complexity[j];
    }
    
    // Initialize indices for both vectors
    int i = 0, j = 0;
    
    // Iterate through both vectors to compare complexities
    while (i < n && j < m) {
        // If the current round's complexity is less than or equal to George's complexity,
        // move to the next round
        if (round_complexity[i] <= george_complexity[j]) {
            i++;
        }
        // Always move to the next complexity of George
        j++;
    }
    
    // Output the number of rounds that George cannot handle
    cout << n - i << endl;

    return 0;
}

// <END-OF-CODE>
