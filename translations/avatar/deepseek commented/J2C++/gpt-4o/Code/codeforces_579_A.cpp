#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation

using namespace std;

int main() {
    int n; // Variable to store the input integer
    cin >> n; // Reading an integer input from the user
    string s = ""; // Initializing an empty string to store binary representation
    
    // Converting the integer to binary representation
    while (n > 0) {
        int x = n % 2; // Getting the remainder when divided by 2
        n /= 2; // Dividing the number by 2
        s += to_string(x); // Appending the remainder to the string
    }
    
    int ans = 0; // Initializing a variable to count the number of '1's
    
    // Counting the number of '1's in the binary representation
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            ans++; // Incrementing the count if the character is '1'
        }
    }
    
    cout << ans << endl; // Printing the count of '1's
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
