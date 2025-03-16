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

// TaskD class containing the solve method
class TaskD {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        // Read the number of elements and the modulo value
        int n, m;
        in >> n >> m;
        
        // Read the array of elements
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            in >> a[i];
        }
        
        // HashMap to store the frequency of remainders
        map<int, int> dp;
        
        // Initialize the answer and base variable
        long ans = 0;
        int base = 0;
        
        // Iterate through the array to calculate the answer
        for (int i = 0; i < n; i++) {
            // Update the base variable
            base = (base - a[i] % m + m) % m;
            
            // Update the frequency of remainders in the HashMap
            dp[((base + a[i]) % m)]++;
            
            // Add the frequency of the current remainder to the answer
            ans += dp[base];
        }
        
        // Print the final answer
        out << ans << endl;
    }
};

// InputReader class to read input efficiently
class InputReader {
public:
    InputReader(istream &in) : in(in) {
        in >> n;
        in >> m;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            in >> a[i];
        }
    }
    
    // Read the next string from the input
    string nextString() {
        return "";
    }
    
    // Read the next integer from the input
    int nextInt() {
        return 0;
    }
    
    // Read the next array of integers from the input
    vector<int> nextIntArray(int n) {
        return vector<int>();
    }
    
private:
    istream &in;
    int n, m;
    vector<int> a;
};

// Main function
int main() {
    // Initialize input and output streams
    InputReader in(cin);
    PrintWriter out(cout);
    
    // Create an instance of TaskD and solve the problem
    TaskD solver;
    solver.solve(1, in, out);
    
    // Close the output stream
    out.close();
}

