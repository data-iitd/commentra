// Import the necessary header for input/output
#include <iostream>

using namespace std;

int main() {
    // Declare two integer variables "n" and "k"
    int n, k;

    // Read the values of "n" and "k" from the standard input
    cin >> n >> k;

    // Check if the value of "k" is less than or equal to the middle index of the slice "n"
    if (k <= (n + n % 2) / 2) {
        // If the condition is true, print "YES" to the standard output
        cout << "YES" << endl;
    } else {
        // If the condition is false, print "NO" to the standard output
        cout << "NO" << endl;
    }

    return 0;
}

// <END-OF-CODE>
