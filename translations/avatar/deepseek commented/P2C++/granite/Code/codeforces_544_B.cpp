

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;  // Read input for n and k
    int x = 0;  // Initialize x to 0

    // Check if k is within the feasible range for placing 'L' characters
    if (k <= max(n * n / 2, n * n - (n * n / 2))) {
        cout << "YES" << endl;  // Print 'YES' if k is feasible
        for (int i = 0; i < n; i++) {  // Loop through each row
            for (int j = 0; j < n; j++) {  // Loop through each column
                if (i % 2 == j % 2 && x < k) {  // Check if the cell should be 'L'
                    cout << "L";  // Print 'L'
                    x++;  // Increment x
                } else {
                    cout << "S";  // Print 'S' otherwise
                }
            }
            cout << endl;  // Move to the next line after each row
        }
    } else {
        cout << "NO" << endl;  // Print 'NO' if k is not feasible
    }

    return 0;
}
