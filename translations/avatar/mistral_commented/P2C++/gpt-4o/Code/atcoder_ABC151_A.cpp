#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Global variable for debug mode
bool debug = false;

// Function to log messages when debug mode is enabled
void log(const string& text) {
    // Check if debug mode is enabled
    if (debug) {
        // Print the log message
        cout << text << endl;
    }
}

// Function to parse input lines
pair<string, vector<string>> parse_input(const string& lines_as_string = "") {
    // Set the global debug flag
    global debug;

    // Initialize an empty vector to store the lines
    vector<string> lines;

    // If lines_as_string is provided, set debug mode to true and parse lines
    if (!lines_as_string.empty()) {
        debug = true;
        size_t start = 0, end = 0;
        while ((end = lines_as_string.find('\n', start)) != string::npos) {
            lines.push_back(lines_as_string.substr(start, end - start));
            start = end + 1;
        }
        lines.push_back(lines_as_string.substr(start)); // Add the last line
    }

    // Extract the first character from the first line as the command
    string c = lines[0].substr(0, 1);

    // Return the command as a pair
    return make_pair(c, lines);
}

// Function to solve the problem based on the command
char solve(const string& c) {
    // Define the alphabet string
    string a = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    size_t i = a.find(c);

    // Return the next character in the alphabet string
    return a[i + 1];
}

// Main function to execute the code
int main() {
    // Call the parse_input function to get the command
    auto parsed = parse_input();
    string command = parsed.first;

    // Solve the problem based on the command
    char result = solve(command);

    // Print the result
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
