#include <bits/stdc++.h>

using namespace std;

// Function to read an integer from standard input
int I() {
    return int(cin.get());
}

// Function to read a list of integers from standard input
vector<int> LI() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    return v;
}

// Main function to solve the problem
int main() {
    // Read the number of test cases
    int N = I();

    // Read the list of integers and sort it in descending order
    vector<int> S = LI();
    sort(S.begin(), S.end(), greater<int>());

    // Initialize a list of flags to keep track of whether each integer has been included in the current subsequence or not
    vector<bool> flag(S.size(), true);

    // Initialize an empty list to store the current subsequence
    vector<int> cur;

    // Start from the first integer and include it in the subsequence
    cur.push_back(S[0]);
    flag[0] = false;

    // For each integer in the sorted list
    for (int i = 0; i < N; i++) {
        // Initialize variables
        int j = 0;
        int jM = cur.size();

        // Try to include the current integer in the subsequence
        for (int k = 0; k < S.size(); k++) {
            // If the flag of the current integer is True and it is smaller than the last integer in the subsequence
            if (flag[k] && S[k] < cur[j]) {
                // Include the current integer in the subsequence and update the flag and the index of the last integer in the subsequence
                cur.push_back(S[k]);
                j++;
                flag[k] = false;
                // If the length of the subsequence hasn't changed, break the loop
                if (j == jM) {
                    break;
                }
            }
        }

        // If we couldn't include any integer in the subsequence after the current one, return "No"
        if (j == jM) {
            return "No";
        }

        // Sort the subsequence in descending order
        sort(cur.begin(), cur.end(), greater<int>());
    }

    // If we could include all the integers in the subsequence, return "Yes"
    return "Yes";
}

