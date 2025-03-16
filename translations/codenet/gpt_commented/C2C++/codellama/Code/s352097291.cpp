#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declare a string 'c' to store the input string and 'ans' to store the result
    string c, ans = "";
    
    // Read a string input from the user
    cin >> c;
    
    // Iterate through each character of the input string until the null terminator is encountered
    for (int i = 0; i < c.length(); i++) {
        // If the current character is not 'B', append it to the 'ans' string
        if (c[i] != 'B') {
            ans += c[i];
        } 
        // If the current character is 'B', remove the last character from 'ans' (if it exists)
        else {
            ans.erase(ans.length() - 1);
        }
    }
    
    // Print the resulting string after processing the input
    cout << ans << endl;
}

