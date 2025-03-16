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
        // Initialize a stack to keep track of characters
        stack<char> s;
        // Initialize a counter to count balanced pairs
        int c = 0;
        // Iterate through each character in the input string
        for (char ch : x) {
            // Push the current character onto the stack
            s.push(ch);
            // While the stack has more than one element, check for balanced pairs
            while (s.size() > 1) {
                // Pop the top two elements from the stack
                char p = s.top();
                s.pop();
                char q = s.top();
                s.pop();
                // Check if they form a balanced pair
                if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                    // Increment the counter if a balanced pair is found
                    c++;
                    continue;
                } else {
                    // If not a balanced pair, push the popped elements back onto the stack
                    s.push(q);
                    s.push(p);
                    break;
                }
            }
        }
        // Output the result, which is twice the counter value
        cout << c * 2 << endl;
    }
};

int main() {
    // Create an instance of TaskB and call its solve method
    TaskB solver;
    solver.solve(1);
    return 0;
}

// <END-OF-CODE>
