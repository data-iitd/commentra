#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

struct op {
    bool rev, front;
    char c;
};

string rev(const string& s) {
    string r = s;
    reverse(r.begin(), r.end());
    return r;
}

int main() {
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<op> ops(Q);
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            ops[i].rev = true;
        } else {
            int f;
            cin >> f >> ops[i].c;
            ops[i].front = (f == 1);
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
        if (!ops[i].rev) { // Not a reverse operation (adding character)
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
