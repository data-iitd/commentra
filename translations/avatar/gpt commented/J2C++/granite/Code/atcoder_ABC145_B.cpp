
#include <iostream> // Importing the standard input/output stream objects
#include <string> // Importing the string class

using namespace std; // Using the standard namespace

// Method to print a string to the console
void cout(string str) {
    cout << str << endl;
}

int main() {
    // Creating variables to hold parts of the input string
    string a = "", b = "", str;
    int n;

    // Reading an integer input which represents the length of the string
    cin >> n;
    cin.ignore(); // Consuming the newline character after the integer input
    
    // Reading the actual string input
    getline(cin, str);

    // Loop to construct the first half of the string
    for (int i = 0; i < n / 2; i++) {
        a = a + str[i]; // Appending characters from the first half of the string to 'a'
    }

    // Checking if the string is made up of two identical halves
    if (str.compare(a + a) == 0) {
        cout("Yes"); // If true, print "Yes"
    } else {
        cout("No"); // If false, print "No"
    }

    return 0; // Returning 0 to indicate successful program execution
}

