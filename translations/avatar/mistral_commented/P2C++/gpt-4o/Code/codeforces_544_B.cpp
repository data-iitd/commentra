#include <iostream>
using namespace std;

int main() {
    // Read input: two integers n and k
    int n, k;
    cin >> n >> k;

    // Initialize variable x to 0
    int x = 0;

    // Check if k is valid based on the condition
    if (k <= max(n * n / 2, n * n - (n * n / 2))) {
        // If k is valid, print 'YES'
        cout << "YES" << endl;

        // Iterate through rows and columns of the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check if current position (i, j) is valid based on the condition
                if (i % 2 == j % 2 && x < k) {
                    // If valid, print 'L' and increment x
                    cout << 'L';
                    x++;
                } else {
                    // If not valid, print 'S'
                    cout << 'S';
                }
            }
            // Move to the next line after completing a row
            cout << endl;
        }
    } else {
        // If k is not valid, print 'NO'
        cout << "NO" << endl;
    }

    return 0;
}

// <END-OF-CODE>
