
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Read the first input as an integer
    int n;
    cin >> n;

    // Check if the input is 1
    if (n == 1) {
        // If the input is 1, print "Hello World"
        cout << "Hello World" << endl;
    } else {
        // If the input is not 1, read two more strings
        string s1, s2;
        cin >> s1 >> s2;

        // Parse the two strings as integers and print their sum
        cout << stoi(s1) + stoi(s2) << endl;
    }

    // Close the input stream
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return 0;
}

