
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initializing the arrays m and f with zeros for all indices up to N
    int N = 368;
    vector<int> m(N, 0);
    vector<int> f(N, 0);

    // Reading the number of operations from the standard input and processing each operation
    for (int i = 0; i < int(input()); i++) {
        // Reading an operation line and splitting it into components
        char x;
        int a, b;
        cin >> x >> a >> b;
        // Incrementing the m array for the 'M' operation and decrementing it for the 'F' operation
        if (x == 'M') {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
    }

    // Initializing three variables a, b, and c with zeros
    int a = 0, b = 0, c = 0;

    // Calculating the prefix sums of m and f arrays
    for (int i = 0; i < N; i++) {
        // Updating the variables a and b with the sum of m and f arrays respectively
        a += m[i];
        b += f[i];
        // Finding the minimum of a and b and updating the variable c if the minimum is greater than the current value of c
        if (min(a, b) > c) {
            c = min(a, b);
        }
    }

    // Printing the result, which is the minimum of the prefix sums of m and f arrays
    cout << c << endl;

    return 0;
}
