#include <iostream>  // Including iostream for input and output
#include <vector>   // Including vector for dynamic array
#include <unordered_set> // Including unordered_set for unique set data structure
#include <string>   // Including string for string manipulation

using namespace std;

int main() {
    // Initializing variables for reading input
    int n, m;
    cin >> n >> m; // Reading the first two integers from the input

    // Creating a vector of strings to store input strings
    vector<string> arrs(n);

    // Iterating through the vector and storing each string
    for (int i = 0; i < n; i++) {
        cin >> arrs[i]; // Reading a string from the input
    }

    // Initializing a vector to store the length of substrings between "G" and "S"
    vector<int> length(n);
    int index = 0; // Index for storing the current index in the length vector
    int returnDex = -1; // Index for storing the index of the string with "G" before "S"

    // Iterating through each string in the vector and finding the length of substrings between "G" and "S"
    for (const string& tmp : arrs) {
        int dexG = tmp.find("G"); // Finding the index of "G" in the current string
        int dexS = tmp.find("S"); // Finding the index of "S" in the current string

        // Checking if "G" comes before "S" in the current string
        if (dexG > dexS) {
            returnDex = index; // Storing the index of the string with "G" before "S"
            break; // Exiting the loop as we have found the required string
        }

        // Storing the length of the substring between "G" and "S" in the length vector
        length[index++] = dexS - dexG;
    }

    // Creating an unordered_set to store the unique lengths of substrings
    unordered_set<int> set;

    // Iterating through the length vector and adding each unique length to the unordered_set
    for (int len : length) {
        set.insert(len);
    }

    // Checking if there is a string with "G" before "S"
    if (returnDex == -1) {
        // Printing the result if there is no such string
        cout << returnDex << endl;
    } else {
        // Printing the size of the unordered_set if there is a string with "G" before "S"
        cout << set.size() << endl;
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
