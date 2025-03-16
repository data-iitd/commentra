#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TaskD {
public:
    void solve(int testNumber) {
        // Read the number of elements and the modulo value
        int n, m;
        cin >> n >> m;

        // Read the array of elements
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // HashMap to store the frequency of remainders
        unordered_map<int, int> dp;

        // Initialize the answer and base variable
        long long ans = 0;
        int base = 0;

        // Iterate through the array to calculate the answer
        for (int i = 0; i < n; i++) {
            // Update the base variable
            base = (base - a[i] % m + m) % m;

            // Update the frequency of remainders in the HashMap
            dp[(base + a[i]) % m]++;

            // Add the frequency of the current remainder to the answer
            ans += dp[base];
        }

        // Print the final answer
        cout << ans << endl;
    }
};

int main() {
    // Create an instance of TaskD and solve the problem
    TaskD solver;
    solver.solve(1);

    return 0;
}

// <END-OF-CODE>
