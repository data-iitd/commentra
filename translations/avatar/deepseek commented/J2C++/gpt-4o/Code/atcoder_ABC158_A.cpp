#include <iostream>
#include <string>

using namespace std;

class AStationAndBus {
public:
    void solve(int testNumber) {
        string s;
        cin >> s; // Reading the input string from the console.
        if (s.find('A') != string::npos && s.find('B') != string::npos) { // Checking if the string contains both 'A' and 'B'.
            cout << "Yes" << endl; // Printing "Yes" if the condition is true.
        } else {
            cout << "No" << endl; // Printing "No" if the condition is false.
        }
    }
};

int main() {
    AStationAndBus solver; // Creating an instance of the AStationAndBus class.
    solver.solve(1); // Calling the solve method to execute the problem-solving logic.
    return 0; // Returning 0 to indicate successful execution.
}

// C++ equivalent of the Java code provided.
// <END-OF-CODE>
