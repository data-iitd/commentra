#include <iostream> // Include the iostream library for input and output operations.
#include <string> // Include the string library for string manipulation.

using namespace std; // Use the standard namespace.

int main() {
    string s; // Define a string variable `s` to store the user input.

    // Print a prompt message to the standard output.
    cout << "Enter a string: ";
    getline(cin, s); // Read a string input from the standard input and store it in the variable `s`.

    // Replace all occurrences of the string "2017" in the string `s` with the string "2018".
    size_t pos = s.find("2017"); // Find the first occurrence of "2017" in the string `s`.
    while (pos != string::npos) { // Loop until no more occurrences are found.
        s.replace(pos, 4, "2018"); // Replace the occurrence with "2018".
        pos = s.find("2017", pos + 4); // Find the next occurrence of "2017" starting from the end of the last replacement.
    }

    // Print the modified string to the standard output.
    cout << "Modified string: " << s << endl;

    return 0; // Return 0 to indicate successful execution.
}

