#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read the input string
    string s;
    cin >> s;
    
    // Check if the string contains both 'A' and 'B'
    if (s.find("A")!= string::npos && s.find("B")!= string::npos) {
        // If both characters are present, print "Yes"
        cout << "Yes" << endl;
    } else {
        // If either character is missing, print "No"
        cout << "No" << endl;
    }
    
    return 0;
}

