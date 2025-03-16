
#include <iostream> // Include the iostream library for input/output operations

using namespace std; // Use the standard namespace for iostream

int main() {
    int T, S, q; // Declare three integer variables: T, S, and q
    
    // Read three integers from the input: T, S, and q
    cin >> T >> S >> q; // Use cin to read input from the console
    
    long long previous = S; // Initialize 'previous' with the starting value S
    int answer = 0; // Initialize the answer counter
    
    // Loop until 'previous' is less than 'T'
    while (previous < T) {
        answer++; // Increment the answer counter
        previous *= q; // Multiply 'previous' by 'q' for the next iteration
    }
    
    // Output the final count of how many times 'previous' was multiplied before reaching 'T'
    cout << answer << endl; // Use cout to output the answer to the console
    
    return 0; // Return 0 to indicate successful program execution
}
