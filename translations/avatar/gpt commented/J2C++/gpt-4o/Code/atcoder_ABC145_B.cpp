#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation

using namespace std; // Using the standard namespace

// Function to print a string to the console
void coutString(const string& str) {
    cout << str << endl;
}

// Main function where the program execution begins
int main() {
    // Initializing variables to hold parts of the input string
    string a = "", str;
    int n;

    // Reading an integer input which represents the length of the string
    cin >> n;
    cin.ignore(); // Consuming the newline character after the integer input

    // Reading the actual string input
    getline(cin, str);

    // Loop to construct the first half of the string
    for (int i = 0; i < n / 2; i++) {
        a += str[i]; // Appending characters from the first half of the string to 'a'
    }

    // Checking if the string is made up of two identical halves
    if (str == a + a) {
        coutString("Yes"); // If true, print "Yes"
    } else {
        coutString("No"); // If false, print "No"
    }

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
