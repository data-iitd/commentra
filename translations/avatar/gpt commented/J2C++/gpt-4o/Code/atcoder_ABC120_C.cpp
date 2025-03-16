#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TaskB {
public:
    void solve(int testNumber) {
        // Read the input string
        string x;
        cin >> x;
        stack<char> s;
        int c = 0; // Counter for pairs of '0' and '1'

        // Iterate through each character in the input string
        for (char ch : x) {
            // Push the current character onto the stack
            s.push(ch);

            // Process the stack while there are at least two characters
            while (s.size() > 1) {
                char p = s.top(); // Get the top character
                s.pop(); // Pop the top character
                char q = s.top(); // Get the next character
                s.pop(); // Pop the next character

                // Check if the characters form a pair of '0' and '1'
                if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                    c++; // Increment the counter for valid pairs
                    continue; // Continue to check for more pairs
                } else {
                    // If not a valid pair, push the characters back onto the stack
                    s.push(q);
                    s.push(p);
                    break; // Exit the while loop
                }
            }
        }
        // Output the result, which is twice the count of pairs found
        cout << c * 2 << endl;
    }
};

int main() {
    // Create an instance of TaskB and solve the problem
    TaskB solver;
    solver.solve(1);

    return 0;
}

// <END-OF-CODE>
