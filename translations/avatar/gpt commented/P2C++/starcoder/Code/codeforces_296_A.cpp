#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read an integer input n which represents the threshold for majority
    int n;
    cin >> n;

    // Read a line of input, split it into a list of strings, and store it in m
    vector<string> m;
    string line;
    getline(cin, line);
    m = line.split();

    // Initialize a variable to track if a majority element is possible
    bool possible = true;

    // Iterate through each unique element in the list m
    for (string i : set<string>(m)) {
        // Check if the count of the current element i is greater than or equal to n/2 + 1
        if (count(m.begin(), m.end(), i) >= n / 2 + 1) {
            // If it is, set possible to False and break the loop
            possible = false;
            break;
        }
    }

    // Print 'YES' if a majority element is not found, otherwise print 'NO'
    cout << (possible? "YES" : "NO") << endl;

    return 0;
}

