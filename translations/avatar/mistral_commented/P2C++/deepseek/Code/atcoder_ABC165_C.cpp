#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the problem
void solve(int N, int M, int Q, vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
    // Initialize result to 0
    int res = 0;

    // Helper function to calculate the answer recursively
    function<void(vector<int>)> rec = [&](vector<int> A) {
        // Base case: if all elements of A are placed, calculate the answer
        if (A.size() == N) {
            int ans = 0;
            for (int i = 0; i < Q; ++i) {
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
        int last_max = A.empty() ? 1 : A.back();
        for (int i = last_max; i <= M; ++i) {
            A.push_back(i);
            rec(A);
            A.pop_back();
        }
    };

    // Call the helper function with an empty list
    rec(vector<int>());

    // Print the result
    cout << res << endl;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> a(Q), b(Q), c(Q), d(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    // Call the solve function with the given input
    solve(N, M, Q, a, b, c, d);

    return 0;
}

