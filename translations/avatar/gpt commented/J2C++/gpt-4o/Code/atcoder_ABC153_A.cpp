#include <iostream>
using namespace std;

int main() {
    // Create variables to hold health and damage
    int h, a;
    
    // Read the initial health and damage dealt per attack
    cin >> h >> a;
    
    // Initialize a counter to keep track of the number of attacks
    int num = 0;
    
    // Loop until the health is greater than zero
    while (h > 0) {
        // Decrease health by the amount of damage dealt
        h -= a;
        
        // Increment the attack counter
        num++;
    }
    
    // Output the total number of attacks required to reduce health to zero or below
    cout << num << endl;

    return 0;
}

// <END-OF-CODE>
