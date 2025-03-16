#include <iostream> // For standard input and output
#include <sstream> // For string stream
#include <string> // For string manipulation
#include <vector> // For using vectors
#include <algorithm> // For using max function

using namespace std;

class FastScanner {
    string line; // To store the input line
    istringstream iss; // To tokenize the input line

public:
    string next() { // Method for reading the next token from the input
        if (!(iss >> line)) { // If there are no more tokens, read a line from the input
            getline(cin, line); // Read a new line
            iss.clear(); // Clear the stream state
            iss.str(line); // Set the new line to the string stream
        }
        return line; // Return the next token
    }

    int nextInt() { // Method for reading the next integer from the input
        return stoi(next()); // Convert the next token to an integer and return it
    }
};

int main() {
    FastScanner in; // Creating an instance of FastScanner class for reading input
    int n = in.nextInt(); // Reading the number of test cases

    int maxSum = 0; // Initializing the maximum sum to zero

    while (n-- > 0) { // Processing each test case
        int f = in.nextInt(); // Reading the first number
        int t = in.nextInt(); // Reading the second number

        maxSum = max(maxSum, f + t); // Updating the maximum sum if the current sum is greater
    }

    cout << maxSum << endl; // Writing the maximum sum to the output
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
