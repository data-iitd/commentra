#include <iostream> // Including the iostream header for input and output

using namespace std; // Using the standard namespace

int main() {
    // Creating a Scanner object to read input from the console
    Scanner in;
    
    // Reading input values for VP, VD, T, F, and C
    double VP = in.nextInt(); // Velocity of the person
    double VD = in.nextInt(); // Velocity of the dog
    double T = in.nextInt();   // Initial time before the dog starts chasing
    double F = in.nextInt();   // Time taken for the dog to return to the person
    double C = in.nextInt();   // Distance the person needs to cover
    
    // If the dog's velocity is less than or equal to the person's velocity, the dog cannot catch up
    if (VD <= VP) {
        cout << "0"; // Output 0 as the dog will never catch the person
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
    
    return 0;
}

