#include <iostream>
#include <string>

using namespace std;

int main() {
    // Reading a string input from the user
    string str;
    cin >> str;
    
    // Reading a long integer input from the user
    long long k;
    cin >> k;
    
    // Getting the length of the input string
    int n = str.length();
    
    // Looping through the first k characters of the string
    for (int i = 0; i < k; i++) {
        // Checking if the current character is '1'
        if (str[i] == '1') {
            // If it's the last character in the range, print 1 and exit
            if (i == k - 1) {
                cout << 1 << endl;
                return 0; // Exit the program
            }
        } else {
            // If the current character is not '1', print it and exit
            cout << str[i] << endl;
            return 0; // Exit the program
        }
    }
}

