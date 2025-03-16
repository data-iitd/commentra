
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a > 0) {
        cout << "Positive" << endl;  // Output 'Positive' if 'a' is greater than 0
    } else if (a <= 0 && b >= 0) {
        cout << "Zero" << endl;  // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
    } else {
        if ((a + b) % 2 == 0) {
            cout << "Negative" << endl;  // Output 'Negative' if the sum of 'a' and 'b' is even
        } else {
            cout << "Positive" << endl;  // Output 'Positive' if the sum of 'a' and 'b' is odd
        }
    }

    return 0;
}
