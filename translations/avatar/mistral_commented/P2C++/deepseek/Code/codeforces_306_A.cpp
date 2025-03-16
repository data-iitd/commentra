#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Calculate the quotient and remainder of n divided by m
    int q = n / m;
    int r = n % m;

    // Initialize the a list with q repeated m times
    int a[m];
    for (int i = 0; i < m; i++) {
        a[i] = q;
    }

    // Increment the corresponding elements in the a list for the remaining elements
    for (int i = 0; i < r; i++) {
        a[i] += 1;
    }

    // Print each element of the a list separated by a space
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}
