#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize a vector 'b' of length 2 * n with all elements as 1
    vector<int> b(2 * n, 1);

    // Set the first, last and middle elements of the vector 'b' to 0
    b[0] = b[n-1] = b[n] = b[2*n-1] = 0;

    // Iterate through the given 'm' pairs of row and column indices
    for (int i = 0; i < m; ++i) {
        int r, c;
        cin >> r >> c;
        
        // Set the elements at the given row and column indices to 0 in the vector 'b'
        b[r-1] = b[n+c-1] = 0;
    }

    // Check if n is odd and if the middle two elements of the vector 'b' are 1, then set the middle element to 0
    if (n % 2 == 1 && b[n/2] == 1 && b[n+n/2] == 1) b[n/2] = 0;

    // Calculate and print the sum of all elements in the vector 'b'
    int sum = 0;
    for (int i = 0; i < 2 * n; ++i) {
        sum += b[i];
    }
    cout << sum << endl;

    return 0;
}
