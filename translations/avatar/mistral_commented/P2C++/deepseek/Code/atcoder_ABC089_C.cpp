#include <bits/stdc++.h>
using namespace std;

// Define constants and global variables
int N;
vector<string> S;
vector<string> march = {"M", "A", "R", "C", "H"};
vector<int> march_lis(5, 0);
int ans = 0;
const int INF = 1e9;
const int mod = 1000000007;

// Function to read input as integer
int input() {
    int x;
    cin >> x;
    return x;
}

// Function to read input as list of integers
vector<int> LIST() {
    vector<int> v;
    int n;
    while (cin >> n) {
        v.push_back(n);
    }
    return v;
}

// Main logic of the code
int main() {
    // Read number of inputs
    N = input();
    // Read list of strings as inputs
    S.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    // Initialize march_lis with zeros
    for (int i = 0; i < 5; ++i) {
        march_lis[i] = 0;
    }

    // Iterate through each string in S and increment the count of the corresponding marching order in march_lis
    for (const auto& s : S) {
        for (int i = 0; i < 5; ++i) {
            if (s == march[i]) {
                march_lis[i]++;
                break;
            }
        }
    }

    // Calculate the answer by finding the triple product of the counts of each marching order
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                ans += march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}
