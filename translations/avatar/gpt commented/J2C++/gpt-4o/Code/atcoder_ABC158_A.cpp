#include <iostream>
#include <string>

using namespace std;

class AStationAndBus {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        // Read the input string
        string s;
        in >> s;

        // Check if the string contains both 'A' and 'B'
        if (s.find('A') != string::npos && s.find('B') != string::npos) {
            // If both characters are present, print "Yes"
            out << "Yes" << endl;
        } else {
            // If either character is missing, print "No"
            out << "No" << endl;
        }
    }
};

int main() {
    // Create an instance of the AStationAndBus class to solve the problem
    AStationAndBus solver;

    // Call the solve method with test number 1, passing the input and output streams
    solver.solve(1, cin, cout);

    return 0;
}

// <END-OF-CODE>
