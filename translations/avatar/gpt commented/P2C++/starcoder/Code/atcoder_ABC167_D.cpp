#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> L(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    L.insert(L.begin(), -1);
    int path[N + 1];
    int ind = 0;
    int count = 0;
    int x = 1;
    int t = -1;
    bool flag = false;
    unordered_map<int, int> Hash;
    for (int i = 0; i < N + 1; i++) {
        int ne = L[x];
        if (Hash[ne]) {
            flag = true;
            t = Hash[ne];
            break;
        }
        path[ind] = ne;
        ind++;
        Hash[ne] = ind;
        x = ne;
    }
    if (flag == true) {
        int loop[N + 1];
        for (int i = t; i < N + 1; i++) {
            loop[i - t] = path[i];
        }
        if (K < N + 1) {
            cout << path[K] << endl;
        } else {
            K = K - N - 1;
            K = K % (N + 1 - t);
            cout << loop[K] << endl;
        }
    } else {
        cout << path[K - 1] << endl;
    }
    return 0;
}

