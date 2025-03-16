#include <iostream>
using namespace std;

int main() {
    // Read two integers from input: n (number of items) and m (total value)
    int n, m;
    cin >> n >> m;

    // Initialize a counter variable i to keep track of the current item
    int i = 1;

    // Loop until m is less than the current item value i
    while (m >= i) {
        // Subtract the current item value i from m
        m -= i;

        // Update i to the next item, wrapping around using modulo n
        i = (i % n) + 1;
    }

    // Print the remaining value of m after the loop ends
    cout << m << endl;

    return 0;
}

// <END-OF-CODE>
