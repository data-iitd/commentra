#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> out(n, 0);
    vector<int> comp(n);
    
    for (int i = 0; i < n; ++i) {
        comp[i] = i + 2;
    }
    
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        int t = l;
        while (t <= r) {
            int next_val = comp[t - 1];
            if (out[t - 1] == 0 && t != x) {
                out[t - 1] = x;
            }
            comp[t - 1] = (t >= x) ? (r + 1) : x;
            t = next_val;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << out[i] << " ";
    }
    cout << endl;

    return 0;
}

// <END-OF-CODE>
