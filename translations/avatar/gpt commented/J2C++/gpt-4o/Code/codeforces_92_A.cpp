#include <iostream> // Including the iostream library for input and output
using namespace std;

int main() {
    // Creating variables to read input from the user
    int n, k;
    
    // Reading two integer inputs: n and k
    cin >> n; // n represents the maximum value for req
    cin >> k; // k is the initial value to be decremented
    
    int i = 1; // Initializing i to 1, which will be used to calculate req
    int req = 1; // Initializing req to 1, which represents the current decrement value
    
    // Loop to decrement k until it is no longer possible
    while (k - req >= 0) {
        // Check if k can be decremented by req
        if (k - req >= 0) {
            k = k - req; // Decrement k by req
        } else {
            break; // Exit the loop if k cannot be decremented by req
        }
        
        i++; // Increment i to determine the next req value
        
        // Determine the next req value based on the current value of i
        if (i % n != 0) {
            req = i % n; // If i is not a multiple of n, set req to i % n
        } else {
            req = n; // If i is a multiple of n, set req to n
        }
    }
    
    // Output the final value of k after all possible decrements
    cout << k << endl;

    return 0; // Indicate that the program ended successfully
}

// <END-OF-CODE>
