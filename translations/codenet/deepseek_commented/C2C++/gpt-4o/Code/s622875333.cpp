#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, r, p, c;
    
    while (true) {
        // Read the values of n and r
        cin >> n >> r;
        // Break the loop if both n and r are zero
        if (n == 0 && r == 0) break;

        // Initialize vector a with values from n down to 1
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = n - i;
        }

        // For each round of r
        for (int i = 0; i < r; i++) {
            // Create a copy of vector a
            vector<int> b = a;

            // Read the values of p and c
            cin >> p >> c;

            // Perform the shift operation on vector a
            for (int j = 0; j < c; j++) {
                a[j] = b[p - 1 + j];
            }

            // Fill the remaining positions in vector a
            for (int j = c; j < c + p - 1; j++) {
                a[j] = b[j - c];
            }
        }
        // Print the first element of vector a
        cout << a[0] << endl;
    }
    return 0;
}

// <END-OF-CODE>
