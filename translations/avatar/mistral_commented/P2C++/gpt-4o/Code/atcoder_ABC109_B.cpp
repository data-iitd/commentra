#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Read the number of elements in the list from user input
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input

    // Initialize an empty unordered_map 's' to count occurrences
    unordered_map<string, int> s;

    // Create a vector 'l' to store the elements
    vector<string> l(n);

    // Read elements from user input into the vector 'l'
    for (int i = 0; i < n; ++i) {
        getline(cin, l[i]);
    }

    // Initialize a flag 'f' with value "Yes"
    string f = "Yes";

    // Initialize an index variable 'i' to track the last processed index
    int i = -1;

    // Iterate through each element 'v' in the vector 'l'
    for (const string& v : l) {
        // Increment the count of 'v' in the unordered_map 's'
        s[v]++;

        // Check if the count of 'v' in unordered_map 's' is greater than or equal to 2
        if (s[v] >= 2) {
            // If yes, set the flag 'f' to "No"
            f = "No";
        }

        // Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
        if (i != -1 && l[i].back() != v[0]) {
            // If yes, set the flag 'f' to "No"
            f = "No";
        }

        // Increment the index 'i'
        i++;
    }

    // Print the final value of flag 'f'
    cout << f << endl;

    return 0;
}

// <END-OF-CODE>
