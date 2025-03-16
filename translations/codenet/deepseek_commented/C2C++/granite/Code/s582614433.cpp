
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

struct Edge {
    ll p;
    int i;
    string s;
};

bool cmp(Edge a, Edge b) {
    if (a.s == b.s) {
        return a.p < b.p;
    }
    return a.s < b.s;
}

int main() {
    ll n;
    cin >> n;
    Edge data[100];
    for (int i = 0; i < n; i++) {
        cin >> data[i].s >> data[i].p;
        data[i].i = i;
    }
    sort(data, data + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << data[i].i + 1 << endl;
    }
    return 0;
}

