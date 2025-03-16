// Import necessary classes
#include <iostream>
#include <string>
#include <sstream>

// Initialize input and output streams
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string token;
        while (iss >> token) {
            cout << token << " ";
        }
        cout << endl;
    }
    return 0;
}

