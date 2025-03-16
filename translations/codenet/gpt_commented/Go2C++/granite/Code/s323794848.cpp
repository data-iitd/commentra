
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define a deque structure with two vectors to represent the front and back.
struct Deque {
    vector<char> front, back;

    // Check if the front of the deque is empty.
    bool isEmptyFront() {
        return front.empty();
    }

    // Check if the back of the deque is empty.
    bool isEmptyBack() {
        return back.empty();
    }

    // Push a character to the back of the deque.
    void pushBack(char c) {
        back.push_back(c);
    }

    // Push a character to the front of the deque.
    void pushFront(char c) {
        front.push_back(c);
    }

    // Pop a character from the back of the deque, or from the front if the back is empty.
    bool popBack(char *c) {
        if (!isEmptyBack()) {
            *c = back.back();
            back.pop_back();
            return true;
        } else if (!isEmptyFront()) {
            *c = front.back();
            front.pop_back();
            return true;
        } else {
            return false; // Return false if both front and back are empty.
        }
    }

    // Pop a character from the front of the deque, or from the back if the front is empty.
    bool popFront(char *c) {
        if (!isEmptyFront()) {
            *c = front.back();
            front.pop_back();
            return true;
        } else if (!isEmptyBack()) {
            *c = back.back();
            back.pop_back();
            return true;
        } else {
            return false; // Return false if both front and back are empty.
        }
    }

    // Get a character at a specific index in the deque.
    char get(int idx) {
        int tot = front.size() + back.size();
        char c;
        if (idx < tot) {
            if (idx < front.size()) {
                c = front[front.size() - 1 - idx]; // Access from the front.
            } else {
                c = back[idx - front.size()]; // Access from the back.
            }
        }
        return c;
    }
};

// Define an operation structure to hold the operation type and character.
struct Op {
    bool rev, front;
    char c;
};

// Reverse a string and return the reversed version.
string rev(string s) {
    string r = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        r += s[i];
    }
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
            char c;
            cin >> f >> c; // Read front/back flag and character.
            if (f == 1) {
                ops[i].front = true; // Mark operation as front insertion.
            }
            ops[i].c = c;
        }
    }

    // Prepare a sum array to track the number of reversals.
    vector<int> sum(Q + 1);
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

    Deque deq; // Initialize a deque to manage character insertions.
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) { // Process only non-reverse operations.
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    deq.pushBack(ops[i].c); // Push to back if the reversal count is odd.
                } else {
                    deq.pushFront(ops[i].c); // Push to front if the reversal count is even.
                }
            } else {
                if (sum[i] % 2 == 1) {
                    deq.pushFront(ops[i].c); // Push to front if the reversal count is odd.
                } else {
                    deq.pushBack(ops[i].c); // Push to back if the reversal count is even.
                }
            }
        }
    }

    // Prepare to write the final result to standard output.
    string result = "";
    // Output the characters in the correct order.
    for (int i = deq.front.size() - 1; i >= 0; i--) {
        result += deq.front[i]; // Add front characters in reverse order.
    }
    for (int i = 0; i < S.size(); i++) {
        result += S[i]; // Add the original string S.
    }
    for (int i = 0; i < deq.back.size(); i++) {
        result += deq.back[i]; // Add back characters in order.
    }
    cout << result << endl; // Print the final result.

    return 0;
}

