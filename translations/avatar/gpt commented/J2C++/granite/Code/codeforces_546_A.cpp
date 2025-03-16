
#include <iostream> // Importing the iostream library for input/output operations

using namespace std; // Using the standard namespace for iostream

int main() {
    // Declaring variables to hold input values and a counter
    long long pandu, vundu, urdu, c = 0;
    
    // Reading three long integer values from user input
    cin >> pandu; // The first input value
    cin >> vundu; // The second input value
    cin >> urdu;  // The third input value
    
    // Calculating the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
    for (int i = 1; i <= urdu; i++) {
        c += i * pandu; // Incrementing 'c' by the product of 'i' and 'pandu'
    }
    
    // Checking if the calculated sum 'c' is less than 'vundu'
    if (c < vundu) {
        cout << "0"; // If true, print "0"
    } else {
        // If 'c' is greater than or equal to 'vundu', print the difference
        cout << c - vundu;
    }
    
    return 0; // Returning 0 to indicate successful program execution
}
