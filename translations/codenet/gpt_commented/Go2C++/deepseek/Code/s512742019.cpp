#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

// Define a constant for modulo operation
const int MOD = 1e9 + 7;
// Define a constant for infinity
const long long INF = 1LL << 60;

// Mon represents a monster with position x and health h
struct Mon {
    int x, h;
};

// Compare function for sorting monsters by their position
bool compareMon(const Mon& a, const Mon& b) {
    return a.x < b.x;
}

// Node represents a position and damage
struct Node {
    int x, h;
};

// Queue is a simple queue implementation for Nodes
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
        return arr.empty();
    }
};

// Calculate the ceiling of a/b
int ceil(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    int N, D, A;
    cin >> N >> D >> A;
    vector<Mon> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i].x >> M[i].h;
    }
    sort(M.begin(), M.end(), compareMon);

    Queue q;
    long long ans = 0;
    long long total = 0;

    for (int i = 0; i < N; i++) {
        Mon m = M[i];
        while (!q.isEmpty() && q.first().x < m.x) {
            total -= q.pop().h;
        }
        if (total < m.h) {
            m.h -= total;
            int count = ceil(m.h, A);
            ans += count;
            long long damage = static_cast<long long>(count) * A;
            q.push({m.x + 2 * D, damage});
            total += damage;
        }
    }

    cout << ans << endl;
    return 0;
}
