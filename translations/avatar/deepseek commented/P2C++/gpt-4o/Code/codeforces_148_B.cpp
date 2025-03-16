#include <iostream>
using namespace std;

int main() {
    int princess, dragon, t, f, c;
    
    cin >> princess;  // Input the number of princess's power
    cin >> dragon;    // Input the number of dragon's power
    cin >> t;         // Input the initial time
    cin >> f;         // Input the time increment
    cin >> c;         // Input the target power level

    // Check if the dragon's power is less than or equal to the princess's power
    if (dragon <= princess) {
        cout << 0 << endl;  // If dragon is not stronger, no attacks needed
        return 0;           // Exit the program
    }

    int result = 0;                // Initialize the result counter
    double position = t * princess; // Calculate the initial position based on time and princess's power
    position += princess * position / (dragon - princess); // Adjust the position based on the given formula

    // Enter a while loop that continues until the position is greater than or equal to the target power level
    while (position < c) {
        result++;         // Increment the result counter
        position += princess * position / dragon;  // Update the position based on the dragon's power
        position += princess * f;  // Add the time increment to the position
        position += princess * position / (dragon - princess); // Adjust the position based on the given formula
    }

    cout << result << endl; // Print the number of attacks needed

    return 0;
} // <END-OF-CODE>
