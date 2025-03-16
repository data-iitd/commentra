

#include <iostream> // Include the necessary header file for input/output operations

using namespace std; // Use the standard namespace for input/output operations

int main() {
    int T, S, q; // Declare the variables T, S, and q as integers
    
    // Read the values of T, S, and q from the user input using cin
    cin >> T >> S >> q;
    
    // Initialize the variable `previous` with the value of S
    long long previous = S;
    
    // Initialize the variable `answer` with the value 0
    int answer = 0;
    
    // Enter a while loop that continues until `previous` is less than T
    while (previous < T) {
        // Inside the loop, multiply `previous` by q and increment the `answer` by 1
        previous *= q;
        answer++;
    }
    
    // After the loop, print the value of `answer` using cout
    cout << answer << endl;
    
    return 0; // Return 0 to indicate successful execution of the program
}

