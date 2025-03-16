#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Read the first input as an integer
    int n;
    cin >> n;

    // Check if the input is 1
    if (n == 1) {
        // If the input is 1, print "Hello World"
        cout << "Hello World" << endl;
    } else {
        // If the input is not 1, read two more integers
        int a, b;
        cin >> a >> b;
        // Print their sum
        cout << (a + b) << endl;
    }

    return 0;
}

// <END-OF-CODE>
