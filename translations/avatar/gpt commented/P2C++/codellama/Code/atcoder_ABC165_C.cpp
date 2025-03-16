#include <iostream>
#include <vector>

using namespace std;

void solve(int N, int M, int Q, vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
    // Initialize the result variable to store the maximum score
    int res = 0;
    
    // Recursive function to explore combinations of numbers
    void rec(vector<int> A) {
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
        if (A.size() > 0) {
            last_max = A[A.size() - 1];
        }
        
        // Iterate through possible values to add to the combination
        for (int i = last_max; i <= M; i++) {
            rec(A);  // Recursively call with the new number added to A
        }
    }
    
    // Start the recursive exploration with an empty list
    rec(vector<int>());
    
    // Print the maximum score found
    cout << res << endl;
}

int main() {
    // Generator function to iterate through input tokens
    auto iterate_tokens() {
        string line;
        while (getline(cin, line)) {
            for (string word : line.split()) {
                yield word;
            }
        }
    }
    
    auto tokens = iterate_tokens();
    
    // Read the values of N, M, and Q from input
    int N = stoi(next(tokens));
    int M = stoi(next(tokens));
    int Q = stoi(next(tokens));
    
    // Initialize lists to hold the query parameters
    vector<int> a(Q);
    vector<int> b(Q);
    vector<int> c(Q);
    vector<int> d(Q);
    
    // Read the query parameters from input
    for (int i = 0; i < Q; i++) {
        a[i] = stoi(next(tokens));
        b[i] = stoi(next(tokens));
        c[i] = stoi(next(tokens));
        d[i] = stoi(next(tokens));
    }
    
    // Call the solve function with the parsed input
    solve(N, M, Q, a, b, c, d);
    
    return 0;
}

