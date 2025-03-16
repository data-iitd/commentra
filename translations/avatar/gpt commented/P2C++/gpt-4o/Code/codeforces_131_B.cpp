#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the elements and count their occurrences using unordered_map
    unordered_map<int, int> w;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        w[x]++;
    }

    // Initialize a counter for pairs that sum to zero
    long long c = 0;

    // Iterate through each unique number in the map
    for (const auto& pair : w) {
        int i = pair.first;
        // Check if the number is zero
        if (i == 0) {
            // For zero, count pairs (w[i] choose 2) since both numbers are the same
            c += (long long)w[i] * (w[i] - 1);
        } else {
            // Check if the negative counterpart exists in the map
            if (w.find(-i) != w.end()) {
                // Count pairs formed by the number and its negative counterpart
                c += (long long)w[i] * w[-i];
            }
        }
    }

    // Since each pair is counted twice, divide the total count by 2 before printing
    cout << c / 2 << endl;

    return 0;
}

// <END-OF-CODE>
