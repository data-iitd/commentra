
#include <bits/stdc++.h> // Import standard library
using namespace std; // Import standard namespace

int main() {
    string a; // Declare a string variable to store the input string

    cin >> a; // Read the input string from the console and store it in the 'a' variable

    // Replace all occurrences of ',' in the 'a' string with a single space
    replace(a.begin(), a.end(), ',','');

    // Print the modified string to the console
    cout << a << endl;

    return 0;
}

