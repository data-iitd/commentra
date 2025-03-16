#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to read an integer from the input
int nextInt() {
    int i;
    cin >> i;
    return i;
}

// Main function
int main() {
    // Read the first three integers from the input
    int a = nextInt();
    int b = nextInt();
    int c = nextInt();

    // Check if the condition is true
    if (a + b >= c) {
        // If true, print "Yes" to the output
        cout << "Yes" << endl;
    } else {
        // If false, print "No" to the output
        cout << "No" << endl;
    }

    // End of code
    return 0;
}

// <END-OF-CODE>
