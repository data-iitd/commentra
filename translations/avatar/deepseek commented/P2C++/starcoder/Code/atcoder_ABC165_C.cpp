
#include <bits/stdc++.h>

using namespace std;

void solve(int N, int M, int Q, vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
    int res = 0;  // Initialize the result variable to store the maximum score

    // Define the recursive function to generate sequences
    void rec(vector<int> &A) {
        if (A.size() == N) {  // If the sequence length is equal to N
            int ans = 0;  // Initialize the answer for this sequence
            for (int i = 0; i < Q; i++) {  // Iterate over all constraints
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {  // Check if the constraint is satisfied
                    ans += d[i];  // Add the value of the constraint to the answer
                }
            }
            res = max(res, ans);  // Update the result with the maximum score
            return;
        }
        int last_max = 1 if (A.size() == 0) else A.back();  // Determine the starting point for the next number
        for (int i = last_max; i <= M; i++) {  // Generate the next number in the sequence
            A.push_back(i);
            rec(A);
            A.pop_back();
        }
    }

    rec({});  // Start the recursive function with an empty list
    cout << res << endl;  // Print the result
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, Q;
    cin >> N >> M >> Q;  // Read the value of N, M, Q
    vector<int> a(Q), b(Q), c(Q), d(Q);  // Initialize the lists a, b, c, d
    for (int i = 0; i < Q; i++) {  // Read the list a
        cin >> a[i];
    }
    for (int i = 0; i < Q; i++) {  // Read the list b
        cin >> b[i];
    }
    for (int i = 0; i < Q; i++) {  // Read the list c
        cin >> c[i];
    }
    for (int i = 0; i < Q; i++) {  // Read the list d
        cin >> d[i];
    }
    solve(N, M, Q, a, b, c, d);  // Call the solve function with the input values
    return 0;
}

