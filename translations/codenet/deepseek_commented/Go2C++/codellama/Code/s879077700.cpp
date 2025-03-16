#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declare a string variable to store the input
    string a;
    
    // Read a string input from the user and store it in `a`
    cin >> a;
    
    // Initialize the variable `ans` with the value "Good"
    string ans = "Good";
    
    // Loop through the first three characters of the string `a`
    for (int i = 0; i < 3; i++) {
        // Check if the current character is the same as the next character
        if (a[i] == a[i+1]) {
            // If the condition is true, change the value of `ans` to "Bad"
            ans = "Bad";
        }
    }
    
    // Print the value of `ans`
    cout << ans << endl;
    
    return 0;
}

