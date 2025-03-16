

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s); // Reading the input string from the console.
    if (s.find("A")!= string::npos && s.find("B")!= string::npos) { // Checking if the string contains both 'A' and 'B'.
        cout << "Yes" << endl; // Printing "Yes" if the condition is true.
    } else {
        cout << "No" << endl; // Printing "No" if the condition is false.
    }
    return 0;
}



