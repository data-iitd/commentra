#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    // Set the recursion limit (not directly applicable in C++)
    // C++ does not have a built-in way to set recursion limits like Python

    // Read input for two numbers 'a' and 'b'
    string sa, sb;
    cin >> sa >> sb;
    int a = stoi(sa);
    int b = static_cast<int>(round(stod(sb) * 100));

    // Calculate the product of 'a' and 'b' and print the result
    cout << (a * b) / 100 << endl;

    return 0;
}

// <END-OF-CODE>
