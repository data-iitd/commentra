#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation

using namespace std;

int main() {
    long a; // Declaring a long integer 'a'
    cin >> a; // Reading a long integer 'a' from the input
    
    string b; // Declaring a string 'b'
    cin >> b; // Reading a string 'b' from the input
    
    string bStr; // Initializing an empty string to store the filtered characters of 'b'
    
    // Looping through the string 'b' to build the string 'bStr' without periods
    for (char c : b) {
        if (c != '.') {
            bStr += c; // Appending non-period characters to 'bStr'
        }
    }
    
    int bInt = stoi(bStr); // Converting 'bStr' to an integer
    long result = (a * bInt) / 100; // Calculating the result of (a * bInt) / 100
    cout << result << endl; // Printing the result to the standard output
    
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
