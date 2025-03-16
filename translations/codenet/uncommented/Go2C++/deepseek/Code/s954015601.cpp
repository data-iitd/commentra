#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int genid(int a, int b) {
    if (b < a) {
        swap(a, b);
    }
    return a * 100000 + b;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> ab(N - 1);
    vector<vector<int>> edges(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ab[i] = {a, b};
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    map<int, int> colors;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, -1, -1));
    while (!q.empty()) {
        int currentNode, usedColor, parentNode;
        tie(currentNode, usedColor, parentNode) = q.front();
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
            q.push(make_tuple(childNode, color, currentNode));
            color++;
        }
    }

    int K = -1;
    for (int i = 0; i < N; i++) {
        if (edges[i].size() > K) {
            K = edges[i].size();
        }
    }
    cout << K << endl;

    for (int i = 0; i < N - 1; i++) {
        cout << colors[genid(ab[i].first, ab[i].second)] << endl;
    }

    return 0;
}
