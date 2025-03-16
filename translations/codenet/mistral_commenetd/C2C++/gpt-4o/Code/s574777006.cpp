#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare variables
    int n, q, sum = 0;
    vector<int> x(10000), y(500);

    // Read the number of elements in the array x
    cin >> n;

    // Read each element of array x
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Read the number of queries
    cin >> q;

    // Read each element of array y
    for (int i = 0; i < q; i++) {
        cin >> y[i];
    }

    // Initialize sum to zero
    sum = 0;

    // Check if each element of array y is present in array x and increment sum if found
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            // Check if current element of y is equal to current element of x
            if (y[i] == x[j]) {
                // Increment sum if found
                sum++;
                // Break out of inner loop as soon as a match is found
                break;
            }
        }
    }

    // Print the value of sum
    cout << sum << endl;

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
