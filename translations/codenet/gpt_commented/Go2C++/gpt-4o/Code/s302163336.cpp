#include <iostream>
#include <vector>

using namespace std;

// Function to read the next integer from standard input
int nextInt() {
    int x;
    cin >> x; // Read the integer
    return x; // Return the integer value
}

int main() {
    // Read the number of elements (n) and the number of comparisons (m)
    int n = nextInt();
    int m = nextInt();

    // Create a vector to hold the heights and a vector to track which elements are "good"
    vector<int> h(n);
    vector<bool> good(n, true); // Initialize all elements as "good"

    // Read the heights
    for (int i = 0; i < n; i++) {
        h[i] = nextInt(); // Read height for each element
    }

    // Process each comparison
    for (int i = 0; i < m; i++) {
        int ai = nextInt() - 1; // Read the first index (0-based)
        int bi = nextInt() - 1; // Read the second index (0-based)

        // Compare the heights and update the good vector accordingly
        if (h[ai] > h[bi]) {
            good[bi] = false; // If ai is taller, bi is not "good"
        } else if (h[ai] < h[bi]) {
            good[ai] = false; // If bi is taller, ai is not "good"
        } else {
            // If heights are equal, mark both as not "good"
            good[ai] = false;
            good[bi] = false;
        }
    }

    // Count the number of "good" elements
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans++; // Increment count for each "good" element
        }
    }

    // Print the result: the number of "good" elements
    cout << ans << endl;

    return 0; // Return success
}

// <END-OF-CODE>
