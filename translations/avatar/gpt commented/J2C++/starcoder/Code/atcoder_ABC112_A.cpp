#include <iostream>
#include <string>
#include <vector>

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
        string str1, str2;
        cin >> str1 >> str2;
        // Parse the two strings as integers and print their sum
        cout << stoi(str1) + stoi(str2) << endl;
    }

    // Close the input stream
    return 0;
}

