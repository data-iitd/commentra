#include <iostream> // Including the iostream library for input and output
using namespace std;

int main() {
    // Reading input values for VP, VD, T, F, and C
    double VP, VD, T, F, C;
    cin >> VP; // Velocity of the person
    cin >> VD; // Velocity of the dog
    cin >> T;  // Initial time before the dog starts chasing
    cin >> F;  // Time taken for the dog to return to the person
    cin >> C;  // Distance the person needs to cover

    // If the dog's velocity is less than or equal to the person's velocity, the dog cannot catch up
    if (VD <= VP) {
        cout << "0" << endl; // Output 0 as the dog will never catch the person
        return 0; // Exit the program
    }

    int answer = 0; // Initialize the number of times the dog catches up
    double start = T; // Start time for the first chase

    // Loop to calculate how many times the dog can catch the person
    while (true) {
        // Calculate the distance the person covers before the dog catches up
        double x = start * VP / (VD - VP);
        
        // Check if the distance covered by the person is greater than or equal to C
        if ((start + x) * VP >= C) {
            break; // Exit the loop if the person has covered the required distance
        }
        
        // Update the start time for the next chase
        start += 2 * x + F; // Add the time taken for the dog to return and the time to catch up
        answer++; // Increment the count of catches
    }

    // Output the total number of times the dog catches the person
    cout << answer << endl;

    return 0; // Exit the program
}

// <END-OF-CODE>
