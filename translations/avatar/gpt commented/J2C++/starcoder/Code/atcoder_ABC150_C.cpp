#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Method to generate all permutations of a given target string
void permutation(vector<string> &list, string target, string ans) {
    // Base case: if the target string is of length 1 or less, add the current answer to the list
    if (target.length() <= 1) {
        list.push_back(ans + target);
    } else {
        // Recursive case: iterate through each character in the target string
        for (int i = 0; i < target.length(); i++) {
            // Recursively call permutation with the remaining characters and the current character added to the answer
            permutation(list, target.substr(0, i) + target.substr(i + 1), ans + target.at(i));
        }
    }
}

int main() {
    // Create a scanner object to read input from the user
    cin >> ws;
    string line[2];
    // Read the number of elements to be processed
    int n;
    cin >> n;
    // Initialize a 2D array to store input strings
    for (int i = 0; i < 2; i++) {
        cin >> line[i];
    }
    // Create a string containing numbers from 1 to n
    string number = "";
    for (int i = 1; i <= n; i++) {
        number += to_string(i);
    }
    // List to hold all permutations of the number string
    vector<string> listA;
    // Generate all permutations of the number string
    permutation(listA, number, "");
    // Variable to hold the sum of indices based on matching permutations
    int sum = 0;
    // Iterate through each row of the input strings
    for (int j = 0; j < 2; j++) {
        // Check each permutation against the input strings
        for (int i = 0; i < listA.size(); i++) {
            // If a permutation matches the input string, adjust the sum based on the index
            if (listA.at(i) == line[j]) {
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

