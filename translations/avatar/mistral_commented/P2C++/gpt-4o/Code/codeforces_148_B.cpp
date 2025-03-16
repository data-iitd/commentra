#include <iostream>
using namespace std;

int main() {
    // Read in five integers from the standard input
    int princess, dragon, t, f, c;
    cin >> princess >> dragon >> t >> f >> c;

    // Check if the dragon is smaller than or equal to the princess
    // If so, print 0 and exit the program
    if (dragon <= princess) {
        cout << 0 << endl;
        return 0;
    }

    // Initialize a variable result to 0
    int result = 0;

    // Calculate an initial position based on t and princess
    double position = t * princess;

    // Enter a while loop that continues as long as the position is less than c
    while (position < c) {
        // Increment result by 1
        result += 1;

        // Update the position by adding the given terms
        position += princess * position / dragon;
        position += princess * f;
        position += princess * position / (dragon - princess);
    }

    // Once the loop terminates, print the final value of result
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
