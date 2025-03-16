// Include necessary headers
#include <iostream>
#include <string>

// Use the standard namespace
using namespace std;

int main() {
    // Declare and initialize two variables: n of type int and s of type string
    int n;
    string s;

    // Use cin to read input from the standard input
    cin >> n;
    cin >> s;

    // Use the string method to count occurrences of "ABC" and print the result
    int count = 0;
    size_t pos = 0;
    while ((pos = s.find("ABC", pos)) != string::npos) {
        count++;
        pos += 3; // Move past the last found occurrence
    }
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
