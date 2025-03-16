#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int a, b;
    map<int, int> counter;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (h[a-1] < h[b-1]) {
            counter[a] = 1;
        } else if (h[a-1] > h[b-1]) {
            counter[b] = 1;
        } else if (h[a-1] == h[b-1]) {
            counter[a] = 1;
            counter[b] = 1;
        }
    }
    cout << n - counter.size() << endl;
    return 0;
}

