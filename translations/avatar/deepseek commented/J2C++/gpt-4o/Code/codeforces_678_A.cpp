#include <iostream> // Step 1: Include the iostream library for input and output.
using namespace std; // Step 2: Use the standard namespace.

int main() { // Step 3: Define the main function.
    int n, k; // Step 4: Declare integer variables n and k.
    cin >> n; // Step 5: Read an integer value from the user and store it in n.
    cin >> k; // Step 6: Read another integer value from the user and store it in k.
    
    n++; // Step 7: Increment the value of n by 1.
    
    int z = 0; // Step 8: Initialize a variable z to 0.
    
    if (n % k != 0) { // Step 9: Check if n is not divisible by k.
        z = k - n % k; // If true, calculate the difference between k and the remainder of n divided by k, and store it in z.
    }
    
    cout << n + z << endl; // Step 10: Print the new value of n plus the value of z.
    
    return 0; // Return 0 to indicate successful completion of the program.
}

// <END-OF-CODE>
