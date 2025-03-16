#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b; // Taking two integer inputs, `a` and `b`.
    
    int hole = 1;
    int i = 0; // Initializing `hole` to 1 and `i` to 0.
    bool check = true; // Setting a boolean variable `check` to `true`.
    
    while (check) {
        if (hole >= b) {
            check = false; // If `hole` is greater than or equal to `b`, set `check` to `false` to exit the loop.
        } else {
            hole = a * (i + 1) - i; // If `hole` is less than `b`, update `hole`.
            i++; // Increment `i` by 1.
        }
    }
    
    cout << i << endl; // Finally, print the value of `i` after the loop exits.
    
    return 0;
}
// <END-OF-CODE>
