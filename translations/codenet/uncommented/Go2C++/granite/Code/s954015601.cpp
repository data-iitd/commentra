
// 深さ優先探索
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int genid(int a, int b) {
    if (b < a) {
        a, b = b, a;
    }
    return a*100000 + b;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> edges(N);
    vector<pair<int, int>> ab(N-1);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ab[i] = make_pair(a, b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    map<int, int> colors;
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(-1, -1)));
    while (!q.empty()) {
        int currentNode = q.front().first;
        int usedColor = q.front().second.first;
        int parentNode = q.front().second.second;
        q.pop();
        int color = 1;
        for (int childNode : edges[currentNode]) {
            if (childNode == parentNode) {
                continue;
            }
            if (color == usedColor) {
                color++;
            }
            colors[genid(currentNode, childNode)] = color;
            q.push(make_pair(childNode, make_pair(color, currentNode)));
            color++;
        }
    }

    int K = -1;
    for (int i = 0; i < N; i++) {
        int t = edges[i].size();
        if (t > K) {
            K = t;
        }
    }
    cout << K << endl;

    for (int i = 0; i < N-1; i++) {
        cout << colors[genid(ab[i].first, ab[i].second)] << endl;
    }

    return 0;
}

