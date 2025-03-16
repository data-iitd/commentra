#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialize an empty list to store the sequence
    vector<int> L;

    // Read input (not used, but could be for prompting the user)
    cin.ignore();

    // Initialize a variable 'r' to keep track of the current number to be added to the list
    int r = 1;

    // Read a line of input, split it into parts, and iterate over each part
    for (string k : cin) {
        // Extend the list 'L' by adding 'r' for 'int(k)' times
        for (int i = 0; i < stoi(k); i++) {
            L.push_back(r);
        }
        // Increment 'r' for the next number
        r++;
    }

    // Read another line of input (not used, but could be for prompting the user)
    cin.ignore();

    // Read a line of input, split it into parts, and iterate over each part
    for (string j : cin) {
        // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
        cout << L[stoi(j) - 1] << endl;
    }

    return 0;
}

