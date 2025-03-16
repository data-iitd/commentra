#include <iostream>
using namespace std;

int main() {
    // Take an integer input `n`
    int n;
    cin >> n;

    // Initialize `l` and `r` to 1 and `n` respectively
    int l = 1;
    int r = n;

    // The `while` loop runs as long as `l` is less than `r`
    while (l < r) {
        // Calculate the midpoint `mid`
        int mid = l + (r - l) / 2;
        // Calculate the triangular number `idxcnt` at `mid`
        double idxcnt = mid * (mid + 1) / 2.0;
        // If `idxcnt` is less than `n`, update `l` to `mid + 1`
        if (idxcnt < n) {
            l = mid + 1;
        } 
        // Otherwise, update `r` to `mid`
        else {
            r = mid;
        }
    }

    // Decrease `l` by 1 and calculate the triangular number `idxcnt` at `l`
    l -= 1;
    double idxcnt = l * (l + 1) / 2.0;

    // Print the difference between `n` and `idxcnt`
    cout << static_cast<int>(n - idxcnt) << endl;

    return 0;
}

// <END-OF-CODE>
