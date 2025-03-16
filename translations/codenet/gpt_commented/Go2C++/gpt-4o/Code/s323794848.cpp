#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

// Define an operation structure to hold the operation type and character.
struct Op {
    bool rev, front;
    char c;
};

// Reverse a string and return the reversed version.
string rev(const string &s) {
    string r(s.rbegin(), s.rend());
    return r;
}

// Main function to execute the program logic.
int main() {
    string S;
    cin >> S; // Read the initial string S.
    int Q;
    cin >> Q; // Read the number of operations Q.
    vector<Op> ops(Q); // Create a vector to hold operations.

    // Read each operation and populate the ops vector.
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            ops[i].rev = true; // Mark operation as reverse.
        } else {
            int f;
            cin >> f >> ops[i].c; // Read front/back flag and character.
            ops[i].front = (f == 1); // Mark operation as front insertion.
        }
    }

    // Prepare a sum array to track the number of reversals.
    vector<int> sum(Q + 1, 0);
    for (int i = Q - 1; i >= 1; i--) {
        if (ops[i].rev) {
            sum[i - 1] = sum[i] + 1; // Increment count if operation is reverse.
        } else {
            sum[i - 1] = sum[i]; // Carry forward the count if not reverse.
        }
    }

    // Reverse the string S if the total number of reversals is odd.
    if (sum[0] % 2 == 1) {
        S = rev(S);
    }

    deque<char> deq; // Initialize a deque to manage character insertions.
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) { // Process only non-reverse operations.
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    deq.push_back(ops[i].c); // Push to back if the reversal count is odd.
                } else {
                    deq.push_front(ops[i].c); // Push to front if the reversal count is even.
                }
            } else {
                if (sum[i] % 2 == 1) {
                    deq.push_front(ops[i].c); // Push to front if the reversal count is odd.
                } else {
                    deq.push_back(ops[i].c); // Push to back if the reversal count is even.
                }
            }
        }
    }

    // Output the characters in the correct order.
    for (int i = deq.size() - 1; i >= 0; i--) {
        cout << deq[i]; // Print front characters in reverse order.
    }
    cout << S; // Print the original string S.
    for (char c : deq) {
        cout << c; // Print back characters in order.
    }
    cout << endl; // Print a newline at the end.

    return 0;
}

// <END-OF-CODE>
