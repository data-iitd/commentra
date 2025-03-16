
#include <iostream> // Include the necessary header files
#include <string>

using namespace std;

int main() {
    string n; // Declare a string variable to store the input string
    cin >> n; // Read the input string from the user
    bool s = false; // Declare a boolean variable to keep track of the state

    // Process each character in the input string
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == '.') { // Check if the current character is a dot
            if (s) { // If the state is true
                cout << 1; // Print '1' and reset the state to false
                s = false;
            } else { // If the state is false
                cout << 0; // Print '0' and set the state to false
                s = false;
            }
        } else { // If the current character is not a dot
            if (s) { // If the state is true
                cout << 2; // Print '2' and reset the state to false
                s = false;
            } else { // If the state is false
                s = true; // Set the state to true
            }
        }
    }
    return 0; // Return 0 to indicate successful execution
}

