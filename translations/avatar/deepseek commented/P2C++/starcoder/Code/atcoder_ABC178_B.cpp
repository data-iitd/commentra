#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Setting IO method to "cin.tie(NULL)".

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // Reading four integers from standard input.

    cout << max(a * c, b * d, a * d, b * c) << endl;
    // Calculating and printing the maximum of four possible products of two of the given numbers.

    return 0;
}
// 