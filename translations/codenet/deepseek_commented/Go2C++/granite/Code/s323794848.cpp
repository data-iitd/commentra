
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Deque {
    vector<char> front, back;

    bool isEmptyFront() {
        return front.empty();
    }

    bool isEmptyBack() {
        return back.empty();
    }

    void pushBack(char v) {
        back.push_back(v);
    }

    void pushFront(char v) {
        front.push_back(v);
    }

    bool popBack(char *v) {
        if (!back.empty()) {
            *v = back.back();
            back.pop_back();
            return true;
        } else if (!front.empty()) {
            *v = front.back();
            front.pop_back();
            return true;
        } else {
            return false;
        }
    }

    bool popFront(char *v) {
        if (!front.empty()) {
            *v = front.back();
            front.pop_back();
            return true;
        } else if (!back.empty()) {
            *v = back.back();
            back.pop_back();
            return true;
        } else {
            return false;
        }
    }

    char get(int idx) {
        int tot = front.size() + back.size();
        char v;
        if (idx < tot) {
            if (idx < front.size()) {
                v = front[front.size() - 1 - idx];
            } else {
                v = back[idx - front.size()];
            }
        }
        return v;
    }
};

struct Op {
    bool rev, front;
    char c;
};

string rev(string s) {
    string r = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        r += s[i];
    }
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
            if (f == 1) {
                ops[i].front = true;
            }
            ops[i].c = c;
        }
    }
    vector<int> sum(Q + 1);
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
    Deque deq;
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) { // Not a reversal operation (string append)
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    deq.pushBack(ops[i].c);
                } else {
                    deq.pushFront(ops[i].c);
                }
            } else {
                if (sum[i] % 2 == 1) {
                    deq.pushFront(ops[i].c);
                } else {
                    deq.pushBack(ops[i].c);
                }
            }
        }
    }
    string ans = "";
    for (int i = deq.front.size() - 1; i >= 0; i--) {
        ans += deq.front[i];
    }
    for (int i = 0; i < S.size(); i++) {
        ans += S[i];
    }
    for (int i = 0; i < deq.back.size(); i++) {
        ans += deq.back[i];
    }
    cout << ans << endl;
    return 0;
}

