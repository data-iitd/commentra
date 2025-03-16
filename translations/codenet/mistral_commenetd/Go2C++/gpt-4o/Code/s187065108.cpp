#include <iostream>
#include <vector>

using namespace std;

// Function to read an integer as input
int scanInt() {
    int num;
    cin >> num; // Read an integer from standard input
    return num; // Return the integer
}

// Main function to execute the program
int main() {
    // Read the first three integers as input
    int r = scanInt();
    int D = scanInt();
    int x = scanInt();

    // Iterate through a loop 10 times
    for (int i = 1; i <= 10; i++) {
        // Calculate the new value of x using the given formula
        x = r * x - D;

        // Print the value of x to the console
        cout << x << endl;
    }

    return 0; // Indicate that the program ended successfully
}

// <END-OF-CODE>
