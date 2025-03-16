// Import necessary C++ libraries
#include <iostream> // For input/output
#include <vector> // For using vectors
using namespace std; // To avoid using std:: prefix

// Main method is the entry point of the program
int main() {
    // Initialize the input stream
    int len;
    cin >> len; // Read the length of the array from user input

    // Allocate memory for the array of integers using a vector
    vector<int> a(len);

    // Read each integer from the user input and store it in the array
    for (int i = 0; i < len; i++) {
        cin >> a[i];
    }

    // Initialize variables for left and right indices and a flag
    int l = 0;
    int r = 0;
    bool flag = false;
    bool isTrue = false; // Initialize isTrue flag

    // Start the loop to search for two non-consecutive numbers
    for (int i = 0; i < len; i++) {
        // Check if the current number is not in its correct position
        if (a[i] != i + 1 && !flag) {
            // Update the left index
            l = i + 1;
            // Set the flag to true to indicate that we have found the first non-consecutive number
            flag = true;
            // Continue to the next iteration of the loop
            continue;
        }

        // Check if the current number is also not in its correct position and the flag is set
        if (a[i] != i + 1 && flag) {
            // Update the right index
            r = i + 1;

            // Check if the difference between the previous number and the current number is greater than 1
            if ((a[r - 1] - a[r - 2] > 0)) {
                // Set the isTrue flag to true if the condition is satisfied
                isTrue = true;
                // Break out of the loop if the flag is set to true
                break;
            }
        }
    }

    // Print the result based on the value of the isTrue flag
    cout << (!isTrue ? to_string(l) + " " + to_string(r) : "0 0") << endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
