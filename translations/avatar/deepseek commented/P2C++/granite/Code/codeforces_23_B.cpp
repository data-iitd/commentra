

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Taking an integer input `n` which represents the number of iterations.
    for (int i = 0; i < n; i++) {  // Looping `n` times.
        int a;
        cin >> a;  // Taking an integer input `a` for each iteration.
        if (a < 2) {  // Checking if `a` is less than 2.
            cout << 0 << endl;  // Printing 0 if `a` is less than 2.
        } else {  // If `a` is not less than 2.
            cout << a - 2 << endl;  // Printing the result of `a - 2`.
        }
    }
    return 0;
}

