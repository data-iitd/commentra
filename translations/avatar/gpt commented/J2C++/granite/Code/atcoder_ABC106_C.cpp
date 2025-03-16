
#include <iostream> // Including the necessary header file
#include <string> // Including the necessary header file

using namespace std; // Using the standard namespace

int main() {
    // Creating a string variable to store the input string
    string str;
    
    // Reading a string input from the user
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
                cout << 1 << endl; // Printing 1 and ending the program
                return 0; // Exiting the program
            }
        } else {
            // If the current character is not '1', print it and exit
            cout << str[i] << endl; // Printing the current character and ending the program
            return 0; // Exiting the program
        }
    }
    
    return 0; // Ending the program
}

