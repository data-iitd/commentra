#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    // Calculate the difference between A and 2 times B
    int ans = A - 2 * B;

    // Check if the difference is negative
    if (ans < 0) {
        // If it is, set it to zero
        ans = 0;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

