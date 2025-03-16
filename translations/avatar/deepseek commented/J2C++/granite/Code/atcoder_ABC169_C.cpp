

#include <iostream> // Including the standard input/output stream objects
#include <string> // Including the string class
#include <cstdlib> // Including the standard library functions

using namespace std; // Using the standard namespace

int main() {
    long a; // Declaring a long integer variable 'a'
    string b; // Declaring a string variable 'b'
    
    cin >> a; // Reading a long integer 'a' from the standard input stream
    cin >> b; // Reading a string 'b' from the standard input stream
    
    string bStr = ""; // Initializing an empty string to store the filtered characters of 'b'
    
    // Looping through the string 'b' to build the string 'bStr' without periods
    for (int i = 0; i < b.length(); i++) {
        if (b[i]!= '.') {
            bStr += b[i]; // Appending non-period characters to 'bStr'
        }
    }
    
    int bInt = stoi(bStr); // Parsing 'bStr' as an integer
    long result = (a * bInt) / 100; // Calculating the result of (a * bInt) / 100
    cout << result << endl; // Printing the result to the standard output stream
    
    return 0; // Returning 0 to indicate successful program execution
}
