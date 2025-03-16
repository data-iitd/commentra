#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Read the values of n and m from standard input

    vector<int> b(2 * n, 1); // Initialize a vector `b` with 1s, size is 2*n

    b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0; // Set specific positions in `b` to 0

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c; // Read each pair of row and column indices
        b[r - 1] = b[n + c - 1] = 0; // Update `b` based on the input pairs
    }

    if (n % 2 && b[n / 2] && b[n + n / 2]) {
        b[n / 2] = 0; // Check if `n` is odd and specific positions in `b` are 1, then set them to 0
    }

    cout << accumulate(b.begin(), b.end(), 0) << endl; // Print the sum of the vector `b`

    return 0;
} // <END-OF-CODE>
