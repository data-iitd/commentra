#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of strings to be processed
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline after the integer input

    // Read the strings and store them in a vector
    vector<string> s;
    string inputLine;
    getline(cin, inputLine);
    
    // Split the input line by space and store in the vector
    size_t pos = 0;
    while ((pos = inputLine.find(' ')) != string::npos) {
        s.push_back(inputLine.substr(0, pos));
        inputLine.erase(0, pos + 1);
    }
    if (!inputLine.empty()) {
        s.push_back(inputLine); // Add the last string
    }

    // Create a map to store the occurrences of each string
    unordered_map<string, int> w;
    for (const auto& str : s) {
        w[str]++;
    }

    // Initialize variables for storing the index of the longest string and its value
    int c = -1;
    string a;

    // Iterate through each string in the map
    for (const auto& pair : w) {
        const string& str = pair.first;
        // If the current string has the maximum occurrences
        if (pair.second == max_element(w.begin(), w.end(), 
            [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; })->second) {
            // If its index in the original list is greater than the current index of the longest string
            auto it = find(s.begin(), s.end(), str);
            int index = distance(s.begin(), it);
            if (index > c) {
                // Update the longest string and its index
                a = str;
                c = index;
            }
        }
    }

    // Print the longest string
    cout << a << endl;

    return 0;
}

// <END-OF-CODE>
