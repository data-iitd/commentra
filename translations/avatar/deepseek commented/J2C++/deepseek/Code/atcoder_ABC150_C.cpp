#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Generates all permutations of a given string
vector<string> permutation(vector<string>& list, const string& target, const string& ans) {
    if (target.length() <= 1) {
        list.push_back(ans + target);
    } else {
        for (size_t i = 0; i < target.length(); i++) {
            permutation(list, target.substr(0, i) + target.substr(i + 1), ans + target[i]);
        }
    }
    return list;
}

int main() {
    int n;
    cin >> n;
    string line[2][1];
    for (int i = 0; i < 2; i++) {
        cin.ignore(); // To ignore the newline character after reading n
        for (int j = 0; j < n; j++) {
            getline(cin, line[i][0]);
            line[i][0] += " "; // Adding a space to concatenate strings correctly
        }
    }
    // Generate the number string for permutations
    string number = "";
    for (int i = 1; i <= n; i++) {
        number += to_string(i);
    }
    // Create a vector to store permutations
    vector<string> listA;
    // Generate all permutations of the number string
    permutation(listA, number, "");
    // Initialize sum to calculate the result
    int sum = 0;
    // Compare permutations with input strings and calculate the sum
    for (int j = 0; j < 2; j++) {
        for (size_t i = 0; i < listA.size(); i++) {
            if (listA[i] == line[j][0]) {
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
