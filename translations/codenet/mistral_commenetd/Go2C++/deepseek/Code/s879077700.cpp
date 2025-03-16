#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare a string variable 'a' to store user input
    string a;

    // Read user input using cin and store it in variable 'a'
    cin >> a;

    // Initialize a string variable 'ans' with value "Good"
    string ans = "Good";

    // Loop through each character in the string 'a' for 3 times
    for (int i = 0; i < 3; i++) {
        // Check if the current character is same as next character
        if (a[i] == a[i + 1]) {
            // Update the value of 'ans' if current and next character are same
            ans = "Bad";
        }
    }

    // Print the final value of 'ans'
    cout << ans << endl;

    return 0;
}

