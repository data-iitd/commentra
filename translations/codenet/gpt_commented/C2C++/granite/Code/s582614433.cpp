
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Edge {
    ll weight;
    ll index;
    string name;
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    if (e1.name == e2.name) {
        return e1.weight > e2.weight;
    }
    return e1.name < e2.name;
}

int main() {
    ll n;
    cin >> n;

    Edge edges[n];
    for (int i = 0; i < n; i++) {
        cin >> edges[i].name >> edges[i].weight;
        edges[i].index = i + 1;
    }

    sort(edges, edges + n, compareEdges);

    for (int i = 0; i < n; i++) {
        cout << edges[i].index << endl;
    }

    return 0;
}

