#include <iostream> // For input and output
#include <string>   // For string manipulation

using namespace std;

class AStationAndBus {
public:
    // Method to solve the problem
    void solve(int testNumber) {
        string s; // Declare a string to hold the input
        cin >> s; // Read the input string

        // Check if the string contains both 'A' and 'B'
        if (s.find('A') != string::npos && s.find('B') != string::npos) {
            cout << "Yes" << endl; // Print "Yes" if both characters are present
        } else {
            cout << "No" << endl; // Print "No" if either character is missing
        }
    }
};

int main() {
    AStationAndBus solver; // Create an instance of the solver class
    solver.solve(1); // Call the solve method with test number

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
