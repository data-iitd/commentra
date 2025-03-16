#include <iostream>  // Including necessary header for input and output operations
#include <vector>   // Including vector header (not used in this code)
#include <algorithm> // Including algorithm header (not used in this code)

using namespace std; // Using the standard namespace

// Main function is the entry point of the C++ application
int main() {
    // Creating variables for reading input
    int a, b;
    // Reading two integers 'a' and 'b' from the standard input
    cin >> a >> b;

    // Initializing variable 'c' to 0
    int c = 0;

    // Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
    if (a == 1 && b == 1) {
        cout << 0 << endl; // Printing 0 as the output
        return 0; // Exiting the main function
    } 
    // If 'a' is not equal to 1 and 'b' is not equal to 1, then perform the following steps
    else {
        // Performing the loop until either 'a' or 'b' becomes 0
        while (a >= 1 || b >= 1) {
            // If 'a' is greater than or equal to 'b', then decrement 'b' and increment 'a' by 2
            if (a >= b) {
                b++;
                a -= 2;
            } 
            // If 'a' is less than 'b', then increment 'a' and decrement 'b' by 2
            else {
                a++;
                b--;
            }

            // Checking if either 'a' or 'b' has become 0. If yes, then increment 'c' and break the loop
            if (a <= 0 || b <= 0) {
                c++;
                break;
            }

            // Incrementing 'c' for each iteration of the loop
            c++;
        }

        // Printing the final result 'c' as the output
        cout << c << endl;
    }

    return 0; // Returning 0 to indicate successful completion
}

// Static method for swapping two integers (not used in this code)
void swap(int a, int b) {
    int t = b;
    b = a;
    a = t;
}

// Static method for debugging purposes (not used in this code)
void debug(const vector<int>& obj) {
    for (const auto& o : obj) {
        cerr << o << " ";
    }
    cerr << endl;
}

// Helper method for exiting the main function (not used in this code)
void exitMainFunction() {
    exit(0);
}
