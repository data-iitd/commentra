#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Create a variable to read input from the user
    long long x;
    
    // Initialize a vector to store the digits after transformation
    vector<long long> list;
    
    // Read a long integer from the user
    cin >> x;
    
    // Process each digit of the number until there are no digits left
    while (x > 0) {
        // Extract the last digit of the number
        long long r = x % 10;
        
        // Determine whether to keep the digit or replace it with its complement to 9
        if (9 - r < r) {
            // If the digit is the last one and its complement is 0, keep the digit
            if (x / 10 == 0 && 9 - r == 0)
                list.push_back(r);
            else
                // Otherwise, add the complement to the list
                list.push_back(9 - r);
        } else
            // If the digit is less than or equal to its complement, keep the digit
            list.push_back(r);
        
        // Remove the last digit from the number
        x = x / 10;
    }
    
    // Initialize variables to construct the new number
    int pow = 0;
    long long newNumber = 0;
    
    // Reconstruct the new number from the transformed digits
    for (int i = 0; i < list.size(); i++) {
        newNumber += list[i] * pow(10, pow);
        pow++;
    }
    
    // Output the newly constructed number
    cout << newNumber << endl;

    return 0;
}

// <END-OF-CODE>
