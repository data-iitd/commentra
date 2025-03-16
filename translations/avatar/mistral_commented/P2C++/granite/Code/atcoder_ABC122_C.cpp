
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// Function definition for counting the number of 'AC' substrings in the given string's'
// The function takes two arguments: 'total' which is the current sum of 'AC' substrings and 'i' which is the index of the current character
int count(int total, int i) {
    // Return the sum of 'total' and 1 if the substring from index 'i-1' to 'i+1' is 'AC'
    return total + (s[i-1] == 'A' && s[i] == 'C');
}

int main() {
    // Taking input for number of strings 'n' and number of problems 'q'
    int n, q;
    cin >> n >> q;

    // Taking input for the string's'
    string s;
    cin >> s;

    // List comprehension to create a list 'problems' of lists containing start and end indices of each problem
    vector<vector<int>> problems(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        problems[i] = {l, r};
    }

    // Using accumulate function to calculate the cumulative sum of 'AC' substrings in the string's'
    vector<int> cumsum(n+1);
    partial_sum(s.begin(), s.end(), cumsum.begin(), count);

    // Iterating through each problem in the list 'problems' and printing the difference between the cumulative sum at the end and start of the problem
    for (const auto& [l, r] : problems) {
        // Print the difference between the cumulative sum at the end and start of the problem
        cout << cumsum[r-1] - cumsum[l-1] << endl;
    }

    return 0;
}
