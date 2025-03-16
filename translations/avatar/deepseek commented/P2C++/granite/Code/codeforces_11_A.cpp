

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    // Taking input for two variables `n` and `d`

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    // Taking input for the vector `x`

    int m = 0, q;
    for (int a = 0; a < n - 1; a++) {
        if (x[a] >= x[a + 1]) {
            q = (x[a] - x[a + 1]) / d + 1;
            m += q;
            x[a + 1] += q * d;
        }
    }
    // Checking if the current element is greater than or equal to the next element
    // Calculating the number of steps `q` needed to make the current element less than the next element by at least `d`
    // Updating the value of `m` by adding `q` to it
    // Updating the next element in the vector `x` by adding `q * d` to it

    cout << m << endl;
    // Printing the value of `m`

    return 0;
}
// End of C++ code