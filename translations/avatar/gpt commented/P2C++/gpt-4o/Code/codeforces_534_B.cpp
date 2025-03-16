#include <iostream>
using namespace std;

int main() {
    // Read initial velocities v1 and v2 from user input
    int v1, v2;
    cin >> v1 >> v2;

    // Read time t and distance increment d from user input
    int t, d;
    cin >> t >> d;

    // Initialize acceleration factor and current velocity
    int a = 1;
    int v = v1;

    // Initialize total distance traveled
    int distance = 0;

    // Loop through each time unit from 0 to t-1
    for (int i = 0; i < t; i++) {
        // Check if the current velocity can exceed the maximum allowed velocity
        if (v - v2 > (t - i - 1) * d) {
            // Reverse acceleration direction if the velocity exceeds the limit
            a *= -1;
            // Adjust current velocity to not exceed the maximum allowed velocity
            v = (t - i - 1) * d + v2;
        }

        // Add current velocity to total distance
        distance += v;

        // Update current velocity based on acceleration direction
        v += a * d;
    }

    // Print the total distance traveled after t time units
    cout << distance << endl;

    return 0;
}

// <END-OF-CODE>
