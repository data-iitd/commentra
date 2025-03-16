
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line); // Read the next line of input
    stringstream ss(line); // Create a stringstream to tokenize the input
    int a, b, c;
    ss >> a >> b >> c; // Read three integers from the input
    if (a + b >= c) {
        cout << "Yes" << endl; // Print "Yes" if the sum is greater than or equal to the third integer
    } else {
        cout << "No" << endl; // Print "No" otherwise
    }
    return 0;
}

