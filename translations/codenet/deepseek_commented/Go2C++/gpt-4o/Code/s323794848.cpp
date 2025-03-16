#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

// Operation struct to store each operation's details
struct Op {
    bool rev, front;
    char c;
};

// Reverse a string
string rev(const string &s) {
    string r(s.rbegin(), s.rend());
    return r;
}

int main() {
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<Op> ops(Q);
    
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            ops[i].rev = true;
        } else {
            int f;
            char c;
            cin >> f >> c;
            ops[i].front = (f == 1);
            ops[i].c = c;
        }
    }

    vector<int> sum(Q + 1, 0);
    for (int i = Q - 1; i >= 1; i--) {
        if (ops[i].rev) {
            sum[i - 1] = sum[i] + 1;
        } else {
            sum[i - 1] = sum[i];
        }
    }

    if (sum[0] % 2 == 1) {
        S = rev(S);
    }

    deque<char> deq;
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) { // Not a reversal operation (string append)
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    deq.push_back(ops[i].c);
                } else {
                    deq.push_front(ops[i].c);
                }
            } else {
                if (sum[i] % 2 == 1) {
                    deq.push_front(ops[i].c);
                } else {
                    deq.push_back(ops[i].c);
                }
            }
        }
    }

    // Output the result
    for (int i = deq.size() - 1; i >= 0; i--) {
        cout << deq[i];
    }
    cout << S;
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i];
    }
    cout << endl;

    return 0;
}

// <END-OF-CODE>
