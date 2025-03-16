
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

// Static inner class to solve the problem
class TaskD {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        // Read input
        int n; // Number of elements in array a
        int m; // Modulus value
        in >> n >> m;

        // Initialize data structures
        vector<int> a(n); // Read array a
        map<int, int> dp; // Hashmap to store intermediate results

        // Initialize variables
        long ans = 0; // Answer variable
        int base = 0; // Base value for hashmap key

        // Process each element in array a
        for (int i = 0; i < n; i++) {
            // Update base value
            base = (base - a[i] % m + m) % m;

            // Update hashmap with current base and its count
            dp[base + a[i] % m]++;

            // Update answer variable
            ans += dp[base];
        }

        // Print the answer
        out << ans << endl;
    }
};

// Static inner class to read input
class InputReader {
public:
    InputReader(istream &in) : in(in) {
        // Nothing to do
    }

    string nextString() { // Read a string token
        string res; // Initialize the result string
        in >> res; // Read the string token
        return res; // Return the result string
    }

    int nextInt() { // Read an integer token
        return stoi(nextString()); // Parse the string token to an integer
    }

    vector<int> nextIntArray(int n) { // Read an array of integers
        vector<int> res(n); // Initialize the result array
        for (int i = 0; i < n; i++) {
            res[i] = nextInt(); // Read each integer and store it in the result array
        }
        return res; // Return the result array
    }

private:
    istream &in; // Input stream
};

int main() {
    InputReader in(cin); // Initialize InputReader
    TaskD solver; // Initialize TaskD solver
    solver.solve(1, in, cout); // Solve the problem and print the result
    return 0;
}

