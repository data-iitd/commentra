#include <iostream>
#include <string>

using namespace std;

// Function to parse input lines
vector<string> parse_input(string lines_as_string=NULL);

// Function to solve the problem based on the command
string solve(string c);

// Main function to execute the code
int main() {
    // Get the command
    vector<string> c = parse_input();

    // Solve the problem
    string result = solve(c[0]);

    // Print the result
    cout << result << endl;

    return 0;
}

// Function to parse input lines
vector<string> parse_input(string lines_as_string=NULL) {
    // Initialize an empty vector to store the lines
    vector<string> lines;

    // If lines_as_string is provided, set debug mode to True and parse lines
    if (lines_as_string!= NULL) {
        // Set debug mode to True
        bool debug = true;

        // Split the lines
        stringstream ss(lines_as_string);
        string line;
        while (getline(ss, line, '\n')) {
            lines.push_back(line);
        }
    }

    // Return the lines
    return lines;
}

// Function to solve the problem based on the command
string solve(string c) {
    // Define the alphabet string
    string a = "abcdefghijklmnopqrstuvwxyz";

    // Find the index of the command character in the alphabet string
    int i = a.find(c);

    // Return the next character in the alphabet string
    return a[i+1];
}

