#include <iostream>
using namespace std;

int main() {
    double VP, VD, T, F, C; // Declare variables for police speed, thief speed, head start time, refuel time, and distance
    cin >> VP >> VD >> T >> F >> C; // Read input values

    if (VD <= VP) {
        cout << "0" << endl; // If the thief's speed is not greater than the police's speed, print 0 and exit
        return 0;
    }

    int answer = 0; // Initialize the answer variable to 0
    double start = T; // Initialize the start variable to the initial head start time (T)

    while (true) {
        double x = start * VP / (VD - VP); // Calculate the distance covered by the police car in one unit of time

        if ((start + x) * VP >= C) {
            break; // If the total distance covered by the police car is greater than or equal to C, break the loop
        }

        start += 2 * x + F; // Update the start variable by adding the distance covered and the refueling time
        answer++; // Increment the answer variable by 1
    }

    cout << answer << endl; // Print the final value of answer
    return 0;
}

// <END-OF-CODE>
