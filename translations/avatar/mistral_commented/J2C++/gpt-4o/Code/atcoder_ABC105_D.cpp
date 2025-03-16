#include <iostream> // For input and output
#include <vector> // For using vectors
#include <unordered_map> // For using unordered_map
#include <string> // For string manipulation

using namespace std;

class TaskD {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        // Read input
        int n, m;
        in >> n >> m; // Number of elements in array a and modulus value

        // Initialize data structures
        vector<int> a(n); // Vector to store array a
        for (int i = 0; i < n; i++) {
            in >> a[i]; // Read array a
        }
        
        unordered_map<int, int> dp; // Unordered map to store intermediate results

        // Initialize variables
        long long ans = 0; // Answer variable
        int base = 0; // Base value for map key

        // Process each element in array a
        for (int i = 0; i < n; i++) {
            // Update base value
            base = (base - a[i] % m + m) % m;

            // Update map with current base and its count
            dp[base + a[i] % m]++;

            // Update answer variable
            ans += dp[base];
        }

        // Print the answer
        out << ans << endl;
    }
};

int main() {
    TaskD solver; // Initialize TaskD solver
    solver.solve(1, cin, cout); // Solve the problem and print the result
    return 0; // Return success
}

// <END-OF-CODE>
