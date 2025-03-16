#include <iostream>
#include <string>

using namespace std;

// Method to generate a character array from the concatenation of numbers 1 to 1000
char* generateString() {
    string s = ""; // Creating a string to efficiently build the string
    
    // Looping through numbers 1 to 1000 and appending them to the string
    for (int i = 1; i <= 1000; i++) {
        s += to_string(i); // Appending the current number to the string
    }
    
    // Converting the built string to a character array and returning it
    return new char[s.length() + 1]{s.c_str()};
}

int main() {
    int n;
    cin >> n;
    
    // Printing the character at the (n-1)th index of the generated character array
    cout << generateString()[n - 1];
    
    return 0;
}

