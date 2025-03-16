#include <iostream> // Include the iostream library for input and output

using namespace std;

int main() {
    // Declare variables for T, S, and q
    int T, S, q;
    
    // Read three integers from the input: T, S, and q
    cin >> T; // The upper limit
    cin >> S; // The starting value
    cin >> q; // The multiplier
    
    long previous = S; // Initialize 'previous' with the starting value S
    int answer = 0; // Initialize the answer counter
    
    // Loop until 'previous' is less than 'T'
    while (previous < T) {
        answer++; // Increment the answer counter
        previous *= q; // Multiply 'previous' by 'q' for the next iteration
    }
    
    // Output the final count of how many times 'previous' was multiplied before reaching 'T'
    cout << answer << endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
