#include <iostream> // Include the iostream library for input and output
using namespace std;

int main() {
    // Read the values of T, S, and q from the user input
    int T, S, q;
    cin >> T >> S >> q;
    
    // Initialize the variable `previous` with the value of S
    long previous = S;
    
    // Initialize the variable `answer` with the value 0
    int answer = 0;
    
    // Enter a while loop that continues until `previous` is less than T
    while (previous < T) {
        // Inside the loop, multiply `previous` by q and increment the `answer` by 1
        previous *= q;
        answer++;
    }
    
    // After the loop, print the value of `answer`
    cout << answer << endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
