// by syu
#include <iostream>
using namespace std;

int main() {
    int n, k;
    // Read two integers n and k from the input
    cin >> n >> k;

    // Check if n is divisible by k
    if (n % k == 0) {
        // If n is divisible by k, print 0
        cout << 0 << endl;
    } else {
        // If n is not divisible by k, print 1
        cout << 1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
