#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Flag to enable or disable debugging
bool debug = false;

// Function to log debug messages
void log(const string& text) {
    if (debug) {
        cout << text << endl;
    }
}

// Function to parse input from the user or from a string
pair<string, bool> parse_input(const string& lines_as_string = "") {
    string c;
    if (lines_as_string.empty()) {
        debug = false;  // Disable debug mode for standard input
        cin >> c;  // Read input from the user
    } else {
        debug = true;  // Enable debug mode for string input
        // Split the input string into lines and ignore the first and last lines
        vector<string> lines;
        size_t start = 0, end = 0;
        while ((end = lines_as_string.find('\n', start)) != string::npos) {
            lines.push_back(lines_as_string.substr(start, end - start));
            start = end + 1;
        }
        lines.push_back(lines_as_string.substr(start)); // Add the last line
        c = lines[1]; // The character to process is in the second line
    }
    return make_pair(c, debug);
}

// Function to solve the problem by finding the next character in the alphabet
char solve(const string& c) {
    string a = "abcdefghijklmnopqrstuvwxyz";  // String containing all lowercase letters
    size_t i = a.find(c);  // Find the index of the given character
    return a[i + 1];  // Return the next character in the alphabet
}

// Main function to execute the program logic
int main() {
    // Parse input and solve the problem
    auto input = parse_input();
    char result = solve(input.first);
    
    // Print the single result
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
