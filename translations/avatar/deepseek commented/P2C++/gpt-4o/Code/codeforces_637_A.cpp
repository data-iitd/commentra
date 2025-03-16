#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // Read the integer n
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input

    // Read the list of strings s
    string line;
    getline(cin, line);
    vector<string> s;
    string word;
    istringstream iss(line);
    while (iss >> word) {
        s.push_back(word);
    }

    // Create a frequency map w from the list s
    unordered_map<string, int> w;
    for (const auto& str : s) {
        w[str]++;
    }

    // Reverse the list s
    reverse(s.begin(), s.end());

    // Initialize two variables c and a to -1 and 0 respectively
    int c = -1;
    string a;

    // Iterate over the items in the frequency map w
    for (const auto& pair : w) {
        const string& i = pair.first;
        // Check if the count of the item is equal to the maximum count in the frequency map
        if (pair.second == max_element(w.begin(), w.end(), 
            [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; })->second) {
            // Check if the index of the item in the reversed list s is greater than the current value of c
            auto it = find(s.begin(), s.end(), i);
            int index = distance(s.begin(), it);
            if (index > c) {
                // Update the value of a to the current item and update the value of c to the index of the current item in the reversed list s
                a = i;
                c = index;
            }
        }
    }

    // Print the value of a
    cout << a << endl;

    return 0;
}
// <END-OF-CODE>
