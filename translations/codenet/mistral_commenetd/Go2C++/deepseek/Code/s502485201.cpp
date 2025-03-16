#include <iostream>
using namespace std;

int main() {
    // Initialize variables r, d, and x with given values
    int r, d, x;
    cin >> r >> d >> x;

    // Loop through 10 iterations
    for (int i = 0; i < 10; i++) {
        // Calculate new value of x using given formula
        x = r * x - d;

        // Print the current value of x
        cout << x << endl;
    }

    return 0;
}
