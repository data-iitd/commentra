
#include <bits/stdc++.h>
using namespace std;
// Include necessary libraries for various functionalities.

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // Reading four integers from standard input.
    cout << max({a * c, b * d, a * d, b * c});
    // Calculating and printing the maximum of four possible products of two of the given numbers.
    return 0;
}
// End of the C++ code.