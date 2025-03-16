#include <iostream>
using namespace std;

int main() {
    double VP, VD, T, F, C;
    cin >> VP >> VD >> T >> F >> C; // Read VP, VD, T, F, C

    if (VD <= VP) { // Check if VD is less than or equal to VP
        cout << "0" << endl; // If it is, then the answer is 0
        return 0; // Return from the method
    }

    int answer = 0;
    double start = T;

    while (true) { // Enter a while loop that runs indefinitely
        double x = start * VP / (VD - VP); // Calculate the time it takes to fill a volume VP

        if ((start + x) * VP >= C) { // Check if the total volume filled is greater than or equal to C
            break; // If it is, then we break out of the loop
        }

        start += 2 * x + F; // Update the value of start
        answer++; // Increment the value of answer
    }

    cout << answer << endl; // Print the value of answer
    return 0; // Return from the method
}

// <END-OF-CODE>
