#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    // Calculate the result by subtracting twice the value of B from A
    int ans = A - 2 * B;

    // If the result is negative, set it to zero
    if (ans < 0) {
        ans = 0;
    }

    // Print the final result
    cout << ans << endl;

    return 0;
}

