#include <bits/stdc++.h>
using namespace std;

int main() {
    // Set up input and output streams
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(cin.failbit);
    
    // Create an instance of TaskB and solve the problem
    TaskB solver;
    solver.solve();
    
    // Close the output stream
    return 0;
}

class TaskB {
    public:
    void solve() {
        // Read the input string
        string x;
        cin >> x;
        
        // Create a stack to store the characters
        stack<char> s;
        int c = 0; // Counter for pairs of '0' and '1'
        
        // Iterate through each character in the input string
        for (int i = 0; i < x.length(); i++) {
            // Push the current character onto the stack
            s.push(x[i]);
            
            // Process the stack while there are at least two characters
            while (s.size() > 1) {
                char p = s.top(); // Pop the top character
                s.pop(); // Pop the next character
                
                // Check if the characters form a pair of '0' and '1'
                if ((p == '1' && s.top() == '0') || (p == '0' && s.top() == '1')) {
                    c++; // Increment the counter for valid pairs
                    continue; // Continue to check for more pairs
                } else {
                    // If not a valid pair, push the characters back onto the stack
                    s.push(p);
                    break; // Exit the while loop
                }
            }
        }
        // Output the result, which is twice the count of pairs found
        cout << c * 2 << "\n";
    }
};

