
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <iomanip>
#include <utility>
#include <bitset>
#include <set>
#include <map>
#include <ios>
#include <cstdlib>
using namespace std;

// Main function starts here
int main() {
    // Declare and initialize variables
    string N; // string to store the input number
    int S = 0; // sum of digits of the number

    // Read the input number from the standard input
    cout << "Enter a number: ";
    cin >> N;

    // Calculate the sum of digits of the number
    for (int i = 0; i < N.size(); i++) {
        // Increment the sum by the ASCII value of the current digit
        // (subtracting the ASCII value of '0' to get the actual digit value)
        S += N[i] - '0';
    }

    // Check if the number is divisible by the sum of its digits
    if (stoi(N) % S == 0) { // Convert the string to an integer using stoi()
        cout << "Yes" << endl; // Output "Yes" if the number is divisible
    } else {
        cout << "No" << endl; // Output "No" otherwise
    }

    // Terminate the program with an exit status of 0
    return 0;
}

