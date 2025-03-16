
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)

struct Mon {
    int x, h;
};

struct Mons {
    vector<Mon> arr;

    bool operator<(const Mons& other) const {
        return arr[0].x < other.arr[0].x;
    }
};

struct Node {
    int x, h;
};

struct Queue {
    vector<Node> arr;

    void push(Node v) {
        arr.push_back(v);
    }

    Node first() {
        return arr[0];
    }

    Node pop() {
        Node res = arr[0];
        arr.erase(arr.begin());
        return res;
    }

    bool isEmpty() {
        return arr.size() == 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, D, A;
    cin >> N >> D >> A;
    vector<Mon> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i].x >> M[i].h;
    }
    sort(M.begin(), M.end());
    Queue q;
    int ans = 0;
    int total = 0;
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
            q.push(Node{m.x + 2*D, damage});
            total += damage;
        }
    }

    cout << ans << endl;

    return 0;
}

