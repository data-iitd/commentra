
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    // Create a string variable to store the input string
    string input;
    // Read the input string from the standard input stream
    getline(cin, input);

    // Get the length of the input string
    int N = input.length();

    // Initialize a set to store unique strings (not used in this code)
    set<string> set;

    // Read the number of queries K
    int K;
    cin >> K;

    // Initialize the result counter
    int res = 0;

    // Loop through each query
    for (int k = 0; k < K; k++) {
        // Read the input string for the current query
        getline(cin, input);

        // Initialize counters for characters in the input string
        int a = 0;
        int b = 0;

        // Iterate through the input string
        for (int i = 0; i < N; i++) {
            // Count occurrences of the first character of the input string
            if (input[i] == input[0])
                a++;
            // Count occurrences of the second character of the input string
            else if (input[i] == input[1])
                b++;
            // If neither character is found, update the result and reset counters
            else {
                res += min(a, b);
                a = b = 0;
            }
        }
        // Add the minimum count of the two characters to the result
        res += min(a, b);
    }

    // Output the final result
    cout << res << endl;

    return 0;
}
