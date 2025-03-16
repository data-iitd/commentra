#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Creating a string to store the input
    string a;
    
    // Reading a line of input from the user
    getline(cin, a);
    
    // Replacing commas in the input string with spaces and appending to StringBuilder
    a.replace(",", " ");
    
    // Printing the modified string to the console
    cout << a << endl;
    
    return 0;
}

