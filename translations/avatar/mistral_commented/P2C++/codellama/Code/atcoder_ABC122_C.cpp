#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

// Function to count the number of 'AC' substrings in the given string 's'
int count(int total, int i) {
    // Return the sum of 'total' and 1 if the substring from index 'i-1' to 'i+1' is 'AC'
    return total + 1 if s[i-1:i+1] == 'AC' else total
}

int main() {
    // Taking input for number of strings 'n' and number of problems 'q'
    int n, q;
    cin >> n >> q;

    // Taking input for the string 's'
    string s;
    cin >> s;

    // List comprehension to create a list 'problems' of lists containing start and end indices of each problem
    vector<vector<int>> problems(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        problems[i] = {l, r};
    }

    // Using accumulate function to calculate the cumulative sum of 'AC' substrings in the string 's'
    vector<int> cumsum(n);
    partial_sum(s.begin(), s.end(), cumsum.begin(), count);

    // Iterating through each problem in the list 'problems' and printing the difference between the cumulative sum at the end and start of the problem
    for (int i = 0; i < q; i++) {
        // Print the difference between the cumulative sum at the end and start of the problem
        cout << cumsum[problems[i][1]-1] - cumsum[problems[i][0]-1] << endl;
    }

    return 0;
}

