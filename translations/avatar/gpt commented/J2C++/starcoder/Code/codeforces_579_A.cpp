#include <bits/stdc++.h>
using namespace std;

int main() {
    // Creating a Scanner object to read input from the user
    cin >> n;
    
    // Initializing an empty string to store the binary representation
    string s = "";
    
    // Converting the integer n to its binary representation
    while (n > 0) {
        int x = n % 2; // Getting the least significant bit (0 or 1)
        n /= 2; // Dividing n by 2 to process the next bit
        s += x + ""; // Appending the bit to the binary string
    }
    
    // Initializing a counter to count the number of '1's in the binary representation
    int ans = 0;
    
    // Iterating through the binary string to count '1's
    for (int i = 0; i < s.length(); i++) {
        if (s.charAt(i) == '1') { // Checking if the current character is '1'
            ans++; // Incrementing the count of '1's
        }
    }
    
    // Printing the total count of '1's in the binary representation
    cout << ans << endl;
}

