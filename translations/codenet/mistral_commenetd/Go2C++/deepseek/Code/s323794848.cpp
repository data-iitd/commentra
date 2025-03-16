#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

// Define a struct to store the operations
struct op {
    bool rev;
    char c;
    bool front;
};

// Function to reverse a given string
string rev(const string& s) {
    string r(s.rbegin(), s.rend());
    return r;
}

int main() {
    // Read the input string S from the standard input
    string S;
    cin >> S;
    // Read the number of operations Q from the standard input
    int Q;
    cin >> Q;
    // Initialize an array of operations ops with the given size
    vector<op> ops(Q);
    // Read the operations one by one and store them in the ops array
    for (int i = 0; i < Q; i++) {
        // Read the type of operation (reverse or not)
        int q;
        cin >> q;
        // If the operation is to reverse the string, set the rev field to true
        if (q == 1) {
            ops[i].rev = true;
        } else {
            // Else, read the front flag and the character c from the standard input
            int f;
            char c;
            cin >> f >> c;
            // Set the front field based on the front flag
            ops[i].front = (f == 1);
            ops[i].c = c;
        }
    }
    // Initialize an array of sums sum with the given size
    vector<int> sum(Q + 1, 0);
    // Initialize the sum of the first operation
    sum[0] = 0;
    // Iterate through the remaining operations and calculate their sums
    for (int i = Q - 1; i >= 0; i--) {
        // If the current operation is to reverse the string, increment the previous sum
        if (ops[i].rev) {
            sum[i] = sum[i + 1] + 1;
        } else {
            // Else, set the previous sum to the current sum
            sum[i] = sum[i + 1];
        }
    }
    // If the sum of the first operation is odd, reverse the input string
    if (sum[0] % 2 == 1) {
        S = rev(S);
    }
    // Initialize an empty deque deq
    deque<char> deq;
    // Iterate through the operations and process them based on their type
    for (int i = 0; i < Q; i++) {
        // If the current operation is not to reverse the string
        if (!ops[i].rev) {
            // If the operation is to add a character at the front, process it accordingly
            if (ops[i].front) {
                // If the previous sum is odd, push the character to the front of the deque
                if (sum[i] % 2 == 1) {
                    deq.push_front(ops[i].c);
                } else {
                    deq.push_back(ops[i].c);
                }
            } else { // Else, process the operation to add a character at the end
                // If the previous sum is odd, push the character to the end of the deque
                if (sum[i] % 2 == 1) {
                    deq.push_back(ops[i].c);
                } else {
                    deq.push_front(ops[i].c);
                }
            }
        }
    }
    // Write the result to the standard output
    for (char c : deq) {
        cout << c;
    }
    // Write the input string to the standard output
    cout << S;
    // Write the characters in the deque to the standard output
    for (char c : deq) {
        cout << c;
    }
    // Flush the buffer and exit
    cout << endl;
    return 0;
}

