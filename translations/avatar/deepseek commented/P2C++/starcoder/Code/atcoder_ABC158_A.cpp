
#include <iostream>
#include <string>

using namespace std;

int main() {
    string stdin;
    cin >> stdin;
    string s = stdin;

    // Check if the string s contains both "A" and "B"
    if (s.find("A")!= string::npos && s.find("B")!= string::npos) {
        string result = "Yes";  // If both "A" and "B" are in the string, set result to "Yes"
    } else {
        string result = "No";  # Otherwise, set result to "No"
    }

    cout << result << endl;  // Print the result

    return 0;
}

