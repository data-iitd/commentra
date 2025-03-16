#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Create a new input stream to read input from the standard input
    int sec; // Number of seconds
    int per_num; // Number of periods
    double max_sec; // Total number of seconds

    // Read three integers from the standard input
    cin >> sec; // Read the number of seconds
    cin >> per_num; // Read the number of periods
    cin >> max_sec; // Read the total number of seconds

    // Add 0.5 to max_sec to get the maximum number of seconds with a fractional part
    max_sec += 0.5;

    // Initialize a counter variable ans_num to zero
    int ans_num = 0;

    // Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec
    for (int i = sec; i < max_sec; i += sec) {
        ans_num += per_num; // In each iteration, add per_num to ans_num
    }

    // Print the result ans_num to the standard output stream
    cout << ans_num << endl;

    return 0; // End of the program
}

// <END-OF-CODE>
