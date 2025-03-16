#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class FastReader {
public:
    FastReader() {}

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
};

int main() {
    // Create a FastReader object to read input
    FastReader sc;

    // Read an integer input
    int x = sc.nextInt();
    // Initialize a counter to keep track of the number of iterations
    int count = 0;
    // Store the initial value of x in a temporary variable
    int tmp = x;

    // Initialize x to 0 to start the loop
    x = 0;

    // Loop until x becomes 360
    while (x != 360) {
        // Increment x by tmp
        x += tmp;
        // If x exceeds 360, adjust it by subtracting 360
        if (x > 360) {
            x -= 360;
        }
        // Increment the counter
        count++;
    }

    // Print the final count
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
