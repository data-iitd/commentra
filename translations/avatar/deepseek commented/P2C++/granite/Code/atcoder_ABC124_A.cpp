

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    // Taking two integer inputs, `a` and `b`, separated by spaces

    int c = 0;
    // Initializing a variable `c` to 0

    for (int i = 0; i < 2; i++) {
        // The loop runs twice
        c += max(a, b);
        // Adding the maximum of `a` and `b` to `c`
        if (a >= b) {
            // Checking if `a` is greater than or equal to `b`
            a -= 1;
            // Decrementing `a` by 1 if the condition is true
        } else {
            b -= 1;
            // Decrementing `b` by 1 if the condition is false
        }
    }

    cout << c << endl;
    // Printing the value of `c` after the loop completes

    return 0;
}
// END-OF-CODE