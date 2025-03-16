#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Generates all permutations of a given string
void permutation(vector<string>& list, string target, string ans) {
    if (target.length() <= 1) {
        list.push_back(ans + target);
    } else {
        for (size_t i = 0; i < target.length(); i++) {
            permutation(list, target.substr(0, i) + target.substr(i + 1), ans + target[i]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    // Initialize a 2D vector to store the input strings
    vector<vector<string>> line(2, vector<string>(1, ""));
    
    for (int i = 0; i < 2; i++) {
        // Read n strings and concatenate them
        for (int j = 0; j < n; j++) {
            string input;
            cin >> input;
            line[i][0] += input;
        }
    }
    
    // Generate the number string for permutations
    string number = "";
    for (int i = 1; i <= n; i++) {
        number += to_string(i);
    }
    
    // Create a list to store permutations
    vector<string> listA;
    // Generate all permutations of the number string
    permutation(listA, number, "");
    
    // Initialize sum to calculate the result
    int sum = 0;
    
    // Compare permutations with input strings and calculate the sum
    for (const auto& str : line) {
        for (size_t i = 0; i < listA.size(); i++) {
            if (listA[i] == str[0]) {
                if (sum == 0) {
                    sum += i;
                } else {
                    sum -= i;
                }
            }
        }
    }
    
    // Print the absolute value of the sum
    cout << abs(sum) << endl;

    return 0;
}

// <END-OF-CODE>
