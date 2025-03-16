#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialize an empty vector to store the sequence
    vector<int> L;

    // Read input (not used, but could be for prompting the user)
    cin.ignore();

    // Initialize a variable 'r' to keep track of the current number to be added to the list
    int r = 1;

    // Read a line of input, split it into parts, and iterate over each part
    string line;
    getline(cin, line);
    for (string k : split(line)) {
        // Extend the vector 'L' by adding 'r' for 'stoi(k)' times
        for (int i = 0; i < stoi(k); i++) {
            L.push_back(r);
        }
        // Increment 'r' for the next number
        r++;
    }

    // Read another line of input (not used, but could be for prompting the user)
    cin.ignore();

    // Read a line of input, split it into parts, and iterate over each part
    getline(cin, line);
    for (string j : split(line)) {
        // Print the element from vector 'L' at the index specified by 'j' (adjusted for 0-based index)
        cout << L[stoi(j) - 1] << endl;
    }

    return 0;
}

// Split a string into parts
vector<string> split(string s) {
    vector<string> parts;
    string part = "";
    for (char c : s) {
        if (c == ' ') {
            parts.push_back(part);
            part = "";
        } else {
            part += c;
        }
    }
    parts.push_back(part);
    return parts;
}

