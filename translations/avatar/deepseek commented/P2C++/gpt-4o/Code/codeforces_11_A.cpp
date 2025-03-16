#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d; // Taking input for two variables `n` and `d`

    vector<int> x(n);
    long long m = 0; // Using long long to avoid overflow
    long long q = 0; // Using long long to avoid overflow

    for (int i = 0; i < n; i++) {
        cin >> x[i]; // Taking input for the list `x`
    }

    for (int a = 0; a < n - 1; a++) {
        if (x[a] >= x[a + 1]) {
            q = (x[a] - x[a + 1]) / d + 1; // Calculating the number of steps `q`
            m += q; // Updating the value of `m`
            x[a + 1] += q * d; // Updating the next element in the list `x`
        }
    }

    cout << m << endl; // Printing the value of `m`
    return 0;
}
// <END-OF-CODE>
