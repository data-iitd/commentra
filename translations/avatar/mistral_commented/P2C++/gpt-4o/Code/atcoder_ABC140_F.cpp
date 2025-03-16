#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer from standard input
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from standard input
vector<int> LI(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return arr;
}

// Main function to solve the problem
string mainFunction() {
    // Read the number of test cases
    int N = I();

    // Read the list of integers and sort it in descending order
    vector<int> S = LI(N);
    sort(S.begin(), S.end(), greater<int>());

    // Initialize a vector of flags to keep track of whether each integer has been included in the current subsequence or not
    vector<bool> flag(S.size(), true);

    // Initialize an empty vector to store the current subsequence
    vector<int> cur;

    // Start from the first integer and include it in the subsequence
    cur.push_back(S[0]);
    flag[0] = false;

    // For each integer in the sorted list
    for (int i = 0; i < N; ++i) {
        // Initialize variables
        int j = 0;
        int jM = cur.size();

        // Try to include the current integer in the subsequence
        for (int k = 0; k < S.size(); ++k) {
            // If the flag of the current integer is true and it is smaller than the last integer in the subsequence
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

// Run the main function if the script is executed directly
int main() {
    // Read the output and print it
    cout << mainFunction() << endl;
    return 0;
}

// <END-OF-CODE>
