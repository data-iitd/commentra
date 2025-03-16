#include <iostream>
using namespace std;

int main() {
    // Creating a Scanner object to read input from the user
    int a, b;
    cin >> a >> b;
    
    // Initializing the result with the value of 'a'
    int res = a;
    
    // Loop to perform the division and accumulate the result
    while (a >= b) {
        // Add the quotient of a divided by b to the result
        res += (a / b);
        
        // Update 'a' to be the sum of the quotient and the remainder
        a = (a / b) + (a % b);
    }
    
    // Output the final result
    cout << res << endl;
    return 0;
}

