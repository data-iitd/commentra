#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem
void solve(int N, int M, int Q, int a[], int b[], int c[], int d[]) {
    // Initialize result to 0
    int res = 0;

    // Helper function to calculate the answer recursively
    void rec(vector<int> &A) {
        // Nonlocal variable to update the result from the recursive calls
        int &res = res;

        // Base case: if all elements of A are placed, calculate the answer
        if (A.size() == N) {
            int ans = 0;
            for (int i = 0; i < Q; i++) {
                // Check if the condition is satisfied
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                    ans += d[i];
                }
            }
            // Update the result with the maximum answer
            res = max(res, ans);
            return;
        }

        // Recursive call: try placing elements from last_max to M
        int last_max = 1 if (A.size() == 0) else A.back();
        for (int i = last_max; i <= M; i++) {
            A.push_back(i);
            rec(A);
            A.pop_back();
        }
    }

    // Call the helper function with an empty list
    rec({});

    // Print the result
    cout << res << endl;
}

// Main function to read input and call the solve function
int main() {
    // Function to generate tokens from standard input
    auto iterate_tokens = []() {
        for (string line; getline(cin, line); ) {
            istringstream iss(line);
            for (string word; iss >> word; ) {
                yield word;
            }
        }
    };

    // Read input tokens
    auto tokens = iterate_tokens();

    // Read number of test cases
    int N = stoi(*tokens++);

    // Read number of elements in the array and number of queries
    int M = stoi(*tokens++);
    int Q = stoi(*tokens++);

    // Read the arrays a, b, c, and d
    vector<int> a(Q), b(Q), c(Q), d(Q);
    for (int i = 0; i < Q; i++) {
        a[i] = stoi(*tokens++);
        b[i] = stoi(*tokens++);
        c[i] = stoi(*tokens++);
        d[i] = stoi(*tokens++);
    }

    // Call the solve function with the given input
    solve(N, M, Q, a.data(), b.data(), c.data(), d.data());
}

