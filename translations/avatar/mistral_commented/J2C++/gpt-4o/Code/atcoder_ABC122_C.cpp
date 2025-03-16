#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1000000007; // Defining a constant value for modulus

int main() { // Main method to start the program
    int n, q; // Declaring variables for length of the string and number of queries
    cin >> n >> q; // Reading the first integer input representing the length of the string and the second integer input representing the number of queries

    string s; // Declaring a string to store the input
    cin >> s; // Reading the string

    vector<vector<int>> range(q, vector<int>(2)); // Declaring and initializing a 2D vector to store the range of each query

    for (int i = 0; i < q; i++) { // Loop to read the range of each query
        cin >> range[i][0] >> range[i][1]; // Reading the starting and ending index of the range
    }

    vector<int> frag(n + 1, 0); // Declaring and initializing a vector to store the frequency of 'AC' substring
    vector<int> rui(n + 1, 0); // Declaring and initializing a vector to store the running sum of 'AC' substring frequency

    for (int i = 2; i <= n; i++) { // Loop to iterate through the string from index 2 to the end
        if (s[i - 2] == 'A' && s[i - 1] == 'C') { // Checking if the current position is an 'AC' substring
            frag[i]++; // Incrementing the frequency of 'AC' substring at the current position
        }
        rui[i] = rui[i - 1] + frag[i]; // Updating the running sum of 'AC' substring frequency
    }

    for (int i = 0; i < q; i++) { // Loop to iterate through each query
        int left = range[i][0]; // Storing the starting index of the current query range
        int right = range[i][1]; // Storing the ending index of the current query range
        cout << rui[right] - rui[left] << endl; // Printing the result of the current query
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
