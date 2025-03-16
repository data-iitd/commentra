#include <iostream>
#include <vector>

// Function to solve the problem
void solve(int N, int M, int Q, std::vector<int> a, std::vector<int> b, std::vector<int> c, std::vector<int> d) {
    // Initialize result to 0
    int res = 0;

    // Helper function to calculate the answer recursively
    void rec(std::vector<int> A) {
        // Nonlocal variable to update the result from the recursive calls
        nonlocal res;

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
            res = std::max(res, ans);
            return;
        }

        // Recursive call: try placing elements from last_max to M
        int last_max = 1;
        if (A.size() > 0) {
            last_max = A.back();
        }
        for (int i = last_max; i <= M; i++) {
            rec(A);
            A.push_back(i);
        }
    }

    // Call the helper function with an empty list
    rec(std::vector<int>());

    // Print the result
    std::cout << res << std::endl;
}

// Main function to read input and call the solve function
int main() {
    // Function to generate tokens from standard input
    std::vector<std::string> tokens;
    std::string token;
    while (std::cin >> token) {
        tokens.push_back(token);
    }

    // Read input tokens
    int N = std::stoi(tokens[0]);
    int M = std::stoi(tokens[1]);
    int Q = std::stoi(tokens[2]);

    // Read the arrays a, b, c, and d
    std::vector<int> a(Q);
    std::vector<int> b(Q);
    std::vector<int> c(Q);
    std::vector<int> d(Q);
    for (int i = 0; i < Q; i++) {
        a[i] = std::stoi(tokens[3 + i * 4]);
        b[i] = std::stoi(tokens[3 + i * 4 + 1]);
        c[i] = std::stoi(tokens[3 + i * 4 + 2]);
        d[i] = std::stoi(tokens[3 + i * 4 + 3]);
    }

    // Call the solve function with the given input
    solve(N, M, Q, a, b, c, d);

    return 0;
}

// 