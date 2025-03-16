#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

// Deque structure to simulate a double-ended queue
class Deque {
public:
    deque<char> front, back;

    // Check if the front of the deque is empty
    bool isEmptyFront() {
        return front.empty();
    }

    // Check if the back of the deque is empty
    bool isEmptyBack() {
        return back.empty();
    }

    // Push a byte to the back of the deque
    void pushBack(char v) {
        back.push_back(v);
    }

    // Push a byte to the front of the deque
    void pushFront(char v) {
        front.push_front(v);
    }

    // Pop a byte from the back of the deque
    bool popBack(char* v) {
        if (!isEmptyBack()) {
            *v = back.back();
            back.pop_back();
            return true;
        } else if (!isEmptyFront()) {
            *v = front.back();
            front.pop_back();
            return true;
        }
        return false;
    }

    // Pop a byte from the front of the deque
    bool popFront(char* v) {
        if (!isEmptyFront()) {
            *v = front.front();
            front.pop_front();
            return true;
        } else if (!isEmptyBack()) {
            *v = back.front();
            back.pop_front();
            return true;
        }
        return false;
    }

    // Get the byte at a specific index in the deque
    char get(int idx) {
        int tot = front.size() + back.size();
        char v = 0;
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

// Operation struct to store each operation's details
struct Op {
    bool rev, front;
    char c;
};

// Reverse a string
string rev(const string& s) {
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
            ops[i].c = c;
            if (f == 1) {
                ops[i].front = true;
            }
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
    for (int i = deq.front.size() - 1; i >= 0; i--) {
        cout << deq.front[i];
    }
    cout << S;
    for (int i = 0; i < deq.back.size(); i++) {
        cout << deq.back[i];
    }
    cout << endl;
    return 0;
}
