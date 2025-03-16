#include <iostream>
#include <string>

using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    string str;
    cin >> str;

    // Initializing variables to hold parts of the input string
    string a = "", b = "";
    int n = str.length();

    // Loop to construct the first half of the string
    for (int i = 0; i < n / 2; i++) {
        a = a + str[i]; // Appending characters from the first half of the string to 'a'
    }

    // Checking if the string is made up of two identical halves
    if (str == a + a) {
        cout << "Yes" << endl; // If true, print "Yes"
    } else {
        cout << "No" << endl; // If false, print "No"
    }

    return 0;
}

