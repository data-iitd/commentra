#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Step 1: Include necessary headers and use the standard namespace.

    int n; // Step 2: Declare an integer n to represent the number of strings.
    cin >> n; // Take an integer input n.
    
    unordered_map<string, int> s; // Step 3: Initialize an unordered_map named s to count occurrences of strings.
    vector<string> l(n); // Step 4: Create a vector l to store n strings.
    
    for (int i = 0; i < n; ++i) {
        cin >> l[i]; // Take n inputs from the user.
    }
    
    string f = "Yes"; // Step 5: Initialize a variable f to "Yes" to keep track of the validity of the sequence.
    int i = -1; // Step 6: Initialize a variable i to -1 to keep track of the index of the current string in the list.

    // Step 7: Enter a for loop to iterate over each string v in the vector l.
    for (const string& v : l) {
        s[v]++; // Step 8: Increment the count of the current string v in the map s.
        if (s[v] >= 2) { // Step 9: If the count of v becomes 2 or more, set f to "No".
            f = "No";
        }
        if (i != -1 && l[i].back() != v.front()) { // Step 10: Check the last character of the previous string.
            f = "No"; // If they don't match, set f to "No".
        }
        i++; // Step 11: Increment the index i after processing each string.
    }

    // Step 12: Print the value of f, which indicates whether the sequence is valid or not.
    cout << f << endl;

    return 0; // End of the main function.
}

// <END-OF-CODE>
