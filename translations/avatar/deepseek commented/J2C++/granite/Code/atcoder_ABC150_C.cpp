

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Generates all permutations of a given string
vector<string> permutation(string target, string ans) {
    vector<string> list;
    if (target.length() <= 1) {
        list.push_back(ans + target);
    } else {
        for (int i = 0; i < target.length(); i++) {
            permutation(target.substr(0, i) + target.substr(i + 1), ans + target[i]);
        }
    }
    return list;
}

int main() {
    // Read the number of strings
    int n;
    cin >> n;
    // Initialize a 2D vector to store the input strings
    vector<vector<string>> line(2, vector<string>(1, ""));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            line[i][0] += s;
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
    listA = permutation(number, "");
    // Initialize sum to calculate the result
    int sum = 0;
    // Compare permutations with input strings and calculate the sum
    for (int j = 0; j < line.size(); j++) {
        for (int i = 0; i < listA.size(); i++) {
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

