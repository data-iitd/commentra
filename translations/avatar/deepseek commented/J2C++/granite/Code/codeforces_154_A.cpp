

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Reading input from standard input
    string line;
    getline(cin, line);
    vector<char> arr(line.begin(), line.end());
    int N = arr.size();

    // Initialize a set to store unique strings and read the number of test cases
    set<string> set;
    int K;
    cin >> K;

    // Initialize the result variable to store the final count
    int res = 0;

    // Loop to process each test case
    for (int k = 0; k < K; k++) {
        string input;
        cin >> input;
        int a = 0, b = 0;

        // Iterate over the characters of the input array
        for (int i = 0; i < N; i++) {
            if (arr[i] == input[0]) // If the character matches the first character of the input
                a++;
            else if (arr[i] == input[1]) // If the character matches the second character of the input
                b++;
            else { // If the character does not match either of the input characters
                res += min(a, b); // Add the minimum of a and b to the result
                a = b = 0; // Reset the counters
            }
        }
        res += min(a, b); // Add the minimum of a and b to the result after the loop
    }

    // Print the final result
    cout << res << endl;

    return 0;
}

