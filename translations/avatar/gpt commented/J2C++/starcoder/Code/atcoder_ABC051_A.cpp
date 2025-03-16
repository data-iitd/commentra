#include <bits/stdc++.h>
using namespace std;

int main() {
    // Creating a stringstream to read input from the console
    stringstream ss;
    ss << "Hello World";
    
    // Using string to efficiently build the output string
    string s;
    
    // Reading a line of input from the user
    getline(ss, s);
    
    // Replacing commas in the input string with spaces
    s.replace(s.find(","), 1, " ");
    
    // Printing the modified string to the console
    cout << s << endl;
    
    return 0;
}

