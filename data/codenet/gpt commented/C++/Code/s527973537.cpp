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

int main() {
    // Read input number as a string
    string N; 
    cin >> N;

    // Initialize a variable to hold the sum of the digits
    int S = 0;

    // Calculate the sum of the digits in the input string
    for (int i = 0; i < N.size(); i++) {
        S += N[i] - '0'; // Convert character to integer and add to sum
    }

    // Check if the original number is divisible by the sum of its digits
    if (stoi(N) % S == 0) 
        cout << "Yes" << endl; // Output "Yes" if divisible
    else 
        cout << "No" << endl; // Output "No" if not divisible

    return 0; // End of the program
}
