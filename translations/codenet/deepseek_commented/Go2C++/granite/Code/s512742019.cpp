
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Scanner {
    Scanner() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
    }

    string nextStr() {
        string s;
        cin >> s;
        return s;
    }

    int nextInt() {
        int i;
        cin >> i;
        return i;
    }

    float nextFloat() {
        float f;
        cin >> f;
        return f;
    }

    vector<rune> nextRuneSlice() {
        string s = nextStr();
        return vector<rune>(s.begin(), s.end());
    }

    vector<int> nextIntSlice(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    vector<float> nextFloatSlice(int n) {
        vector<float> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextFloat();
        }
        return res;
    }
};

int max(int a, int b) {
    return a > b? a : b;
}

int min(int a, int b) {
    return a < b? a : b;
}

int abs(int x) {
    return x > 0? x : -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

int ceil(int a, int b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

struct Mon {
    int x, h;
};

struct Node {
    int x, h;
};

struct Queue {
    queue<Node> q;

    void push(Node v) {
        q.push(v);
    }

    Node first() {
        return q.front();
    }

    Node pop() {
        Node res = q.front();
        q.pop();
        return res;
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    Scanner sc;
    int N = sc.nextInt(), D = sc.nextInt(), A = sc.nextInt();
    vector<Mon> M(N);
    for (int i = 0; i < N; i++) {
        M[i] = {sc.nextInt(), sc.nextInt()};
    }
    sort(M.begin(), M.end(), [](const Mon& a, const Mon& b) {
        return a.x < b.x;
    });
    Queue q;
    int ans = 0, total = 0;
    for (int i = 0; i < N; i++) {
        Mon m = M[i];
        while (!q.isEmpty() && q.first().x < m.x) {
            total -= q.pop().h;
        }
        if (total < m.h) {
            m.h -= total;
            int count = ceil(m.h, A);
            ans += count;
            int damage = count * A;
            q.push({m.x + 2 * D, damage});
            total += damage;
        }
    }

    cout << ans << endl;
    return 0;
}

The above C++ code is a translation of the given Go code. It includes the necessary data structures and functions to solve the problem. The code also includes the required header files and uses the same framework and technology as the given Go code.