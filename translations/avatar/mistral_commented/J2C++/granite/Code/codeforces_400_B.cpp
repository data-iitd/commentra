

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Initializing Scanner object for reading input
    Scanner sc(cin);

    // Reading the first two integers from the input
    int n, m;
    cin >> n >> m;

    // Creating an array of strings to store input strings
    string arrs[n];

    // Iterating through the array and storing each string
    for (int i = 0; i < n; i++) {
        cin >> arrs[i]; // Reading a string from the input
    }

    // Initializing an integer array to store the length of substrings between "G" and "S"
    int length[n];
    int index = 0; // Index for storing the current index in the length array
    int returnDex = 0; // Index for storing the index of the string with "G" before "S"

    // Iterating through each string in the array and finding the length of substrings between "G" and "S"
    for (string tmp : arrs) {
        int dexG = tmp.find("G"); // Finding the index of "G" in the current string
        int dexS = tmp.find("S"); // Finding the index of "S" in the current string

        // Checking if "G" comes before "S" in the current string
        if (dexG > dexS) {
            returnDex = i; // Storing the index of the string with "G" before "S"
            break; // Exiting the loop as we have found the required string
        }

        // Storing the length of the substring between "G" and "S" in the length array
        length[index++] = dexS - dexG;
    }

    // Creating a HashSet to store the unique lengths of substrings
    unordered_set<int> set;

    // Iterating through the length array and adding each unique length to the HashSet
    for (int len : length) {
        set.insert(len);
    }

    // Checking if there is a string with "G" before "S"
    if (returnDex == -1) {
        // Printing the result if there is no such string
        cout << returnDex << endl;
    } else {
        // Printing the size of the HashSet if there is a string with "G" before "S"
        cout << set.size() << endl;
    }

    return 0;
}

These comments should provide a clear understanding of the logic behind each block of code.