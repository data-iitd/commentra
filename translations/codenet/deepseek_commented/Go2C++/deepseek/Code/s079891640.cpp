#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s; // Read the input string from standard input

    for (int i = 0; i < s.length(); i++) { // Iterate over each character in the string
        if (s.find(s[i], i + 1) != string::npos) { // Check if the character appears again in the substring
            cout << "no" << endl; // If it does, print "no" and exit
            return 0;
        }
    }

    cout << "yes" << endl; // If no character appears again, print "yes"
    return 0;
}
