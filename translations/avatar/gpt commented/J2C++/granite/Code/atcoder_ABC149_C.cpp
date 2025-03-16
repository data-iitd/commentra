
#include <iostream> // Include the standard input/output stream objects
#include <cmath> // Include the mathematical functions

using namespace std; // Use the standard namespace

int main() {
    int x; // Declare an integer variable x
    
    // Read an integer input from the user
    cin >> x;
    
    // If x is even and not equal to 2, increment x to make it odd
    if (x!= 2 && x % 2 == 0) 
        x++;
    
    // Infinite loop to find the next prime number
    while (true) {
        int i; // Declare an integer variable i
        
        // Calculate the square root of x for optimization
        double sqrtNum = sqrt(x);
        
        // Check for factors of x from 3 to the square root of x, incrementing by 2 (to check only odd numbers)
        for (i = 3; i <= sqrtNum; i += 2) {
            // If i divides x, then x is not prime
            if (x % i == 0) 
                break; // Exit the loop if a divisor is found
        }
        
        // If no divisors were found, i will be greater than sqrtNum, indicating x is prime
        if (i > sqrtNum) 
            break; // Exit the while loop as we found a prime number
        
        // Increment x by 2 to check the next odd number
        x += 2;
    }
    
    // Output the next prime number
    cout << x << endl; // Use endl to insert a new line after printing the result
    
    return 0; // Return 0 to indicate successful program execution
}

