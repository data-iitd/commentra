#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TaskD {
public:
    void solve(int testNumber) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_map<int, int> dp;
        long long ans = 0; // Variable to store the final answer
        int base = 0; // Variable to track the base remainder

        // Iterate through the array to calculate the answer
        for (int i = 0; i < n; i++) {
            // Update the base remainder
            base = (base - a[i] % m + m) % m;

            // Merge the current remainder into the unordered_map
            dp[(base + a[i]) % m]++;

            // Add the count of occurrences of the current base remainder to the answer
            ans += dp[base];
        }

        // Output the final answer
        cout << ans << endl;
    }
};

int main() {
    // Create an instance of TaskD to solve the problem
    TaskD solver;

    // Solve the problem for the first test case
    solver.solve(1);

    return 0;
}

// <END-OF-CODE>
