#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initializing the constant N
    const int N = 368;
    // Initializing the vectors m and f with zeros
    vector<int> m(N, 0);
    vector<int> f(N, 0);

    // Reading the number of operations
    int operations;
    cin >> operations;
    cin.ignore(); // To ignore the newline character after the integer input

    // Processing each operation
    for (int i = 0; i < operations; i++) {
        string x;
        int a, b;
        cin >> x >> a >> b;
        b += 1; // Incrementing b by 1

        // If the operation is 'M', updating the m vector accordingly
        if (x == "M") {
            m[a] += 2;
            m[b] -= 2;
        }
        // If the operation is 'F', updating the f vector accordingly
        else {
            f[a] += 2;
            f[b] -= 2;
        }
    }

    // Initializing three variables a, b, and c with zeros
    int a = 0, b = 0, c = 0;

    // Calculating the prefix sums of m and f vectors
    for (int i = 0; i < N; i++) {
        a += m[i];
        b += f[i];
        // Finding the minimum of a and b and updating c if the minimum is greater than the current value of c
        if (min(a, b) > c) {
            c = min(a, b);
        }
    }

    // Printing the result, which is the minimum of the prefix sums of m and f vectors
    cout << c << endl;

    return 0;
}

// <END-OF-CODE>
