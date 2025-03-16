
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int N, int M, int Q, vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
    // Initialize the result variable to store the maximum score
    int res = 0;
    
    // Recursive function to explore combinations of numbers
    function<void(vector<int>&)> rec = [&](vector<int>& A) {
        // Base case: if the length of A equals N, calculate the score
        if (A.size() == N) {
            int ans = 0;
            // Check each query to see if it contributes to the score
            for (int i = 0; i < Q; i++) {
                if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                    ans += d[i];  // Add the score from the query if it matches
                }
            }
            // Update the maximum score found
            res = max(res, ans);
            return;
        }
        
        // Determine the starting point for the next number to be added
        int last_max = 1;
        if (!A.empty()) {
            last_max = A.back() + 1;
        }
        
        // Iterate through possible values to add to the combination
        for (int i = last_max; i <= M; i++) {
            A.push_back(i);
            rec(A);  // Recursively call with the new number added to A
            A.pop_back();
        }
    };
    
    // Start the recursive exploration with an empty list
    vector<int> A;
    rec(A);
    
    // Print the maximum score found
    cout << res << endl;
}

int main() {
    // Read the values of N, M, and Q from input
    int N, M, Q;
    cin >> N >> M >> Q;
    
    // Initialize vectors to hold the query parameters
    vector<int> a(Q), b(Q), c(Q), d(Q);
    
    // Read the query parameters from input
    for (int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    // Call the solve function with the parsed input
    solve(N, M, Q, a, b, c, d);
    
    return 0;
}

