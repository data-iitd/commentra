
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to generate all permutations of a given target string
vector<string> permutation(string target, string ans) {
    vector<string> list;
    // Base case: if the target string is of length 1 or less, add the current answer to the list
    if (target.length() <= 1) {
        list.push_back(ans + target);
    } else {
        // Recursive case: iterate through each character in the target string
        for (int i = 0; i < target.length(); i++) {
            // Recursively call permutation with the remaining characters and the current character added to the answer
            vector<string> temp = permutation(target.substr(0, i) + target.substr(i + 1), ans + target[i]);
            list.insert(list.end(), temp.begin(), temp.end());
        }
    }
    // Return the list of permutations
    return list;
}

int main() {
    // Create a scanner object to read input from the user
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    // Initialize a 2D vector to store input strings
    vector<vector<string>> line(2, vector<string>(1, ""));
    // Read n strings from the user and concatenate them into the first column of the vector
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        line[0][0] += s;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        line[1][0] += s;
    }
    // Create a string containing numbers from 1 to n
    string number = "";
    for (int i = 1; i <= n; i++) {
        number += to_string(i);
    }
    // List to hold all permutations of the number string
    vector<string> listA = permutation(number, "");
    // Variable to hold the sum of indices based on matching permutations
    int sum = 0;
    // Iterate through each row of the input strings
    for (int j = 0; j < line.size(); j++) {
        // Check each permutation against the input strings
        for (int i = 0; i < listA.size(); i++) {
            // If a permutation matches the input string, adjust the sum based on the index
            if (listA[i] == line[j][0]) {
                if (sum == 0) {
                    sum += i; // Add index if sum is initially zero
                } else {
                    sum -= i; // Subtract index if sum is not zero
                }
            }
        }
    }
    // Output the absolute value of the sum
    cout << abs(sum) << endl;
    return 0;
}

