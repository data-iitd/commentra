
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Deque {
    vector<char> front, back;

    bool isEmptyFront() const {
        return front.empty();
    }

    bool isEmptyBack() const {
        return back.empty();
    }

    void pushBack(char v) {
        back.push_back(v);
    }

    void pushFront(char v) {
        front.push_back(v);
    }

    bool popBack(char *v) {
        if (!isEmptyBack()) {
            *v = back.back();
            back.pop_back();
            return true;
        } else if (!isEmptyFront()) {
            *v = front.back();
            front.pop_back();
            return true;
        } else {
            return false;
        }
    }

    bool popFront(char *v) {
        if (!isEmptyFront()) {
            *v = front.back();
            front.pop_back();
            return true;
        } else if (!isEmptyBack()) {
            *v = back.back();
            back.pop_back();
            return true;
        } else {
            return false;
        }
    }

    char get(int idx) const {
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

int main() {
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<bool> rev(Q);
    vector<bool> front(Q);
    vector<char> c(Q);
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            rev[i] = true;
        } else {
            cin >> front[i] >> c[i];
            if (front[i]) {
                front[i] = true;
            } else {
                front[i] = false;
            }
        }
    }
    vector<int> sum(Q + 1);
    for (int i = Q - 1; i >= 1; i--) {
        if (rev[i]) {
            sum[i - 1] = sum[i] + 1;
        } else {
            sum[i - 1] = sum[i];
        }
    }
    if (sum[0] % 2 == 1) {
        reverse(S.begin(), S.end());
    }
    Deque deq;
    for (int i = 0; i < Q; i++) {
        if (!rev[i]) { // 反転ではない(文字列追加)
            if (front[i]) {
                if (sum[i] % 2 == 1) {
                    deq.pushBack(c[i]);
                } else {
                    deq.pushFront(c[i]);
                }
            } else {
                if (sum[i] % 2 == 1) {
                    deq.pushFront(c[i]);
                } else {
                    deq.pushBack(c[i]);
                }
            }
        }
    }
    string ans;
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

