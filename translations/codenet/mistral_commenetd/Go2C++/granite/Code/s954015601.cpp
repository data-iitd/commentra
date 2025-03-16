
// 幅優先探索
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

// 2 つの integers を使って一意な ID を生成する
int genid(int a, int b) {
    if (b < a) swap(a, b);
    return a * 100000 + b;
}

int main() {
    int N; cin >> N;
    vector<vector<int>> edges(N);
    vector<pair<int, int>> ab(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        ab[i] = make_pair(a, b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    map<int, int> colors;
    queue<pair<int, int>> q;
    q.push(make_pair(0, -1));
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        int color = 1;
        for (int child : edges[node]) {
            if (child == parent) continue;
            if (color == colors[genid(node, parent)]) color++;
            colors[genid(node, child)] = color;
            q.push(make_pair(child, node));
            color++;
        }
    }
    int K = 0;
    for (int i = 0; i < N; i++) {
        K = max(K, (int)edges[i].size());
    }
    cout << K << endl;
    for (int i = 0; i < N - 1; i++) {
        cout << colors[genid(ab[i].first, ab[i].second)] << endl;
    }
    return 0;
}

// 定数
const int ioBufferSize = 1 * 1024 * 1024; // 1 MB

// ҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆҆<fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad><fim_pad