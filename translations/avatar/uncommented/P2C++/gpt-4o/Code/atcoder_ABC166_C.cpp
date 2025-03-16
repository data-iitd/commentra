#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }
    
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    unordered_map<int, int> hp;
    for (int i = 0; i < n; ++i) {
        hp[p[i]] = h[i];
    }
    
    unordered_map<int, vector<int>> path;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    
    int c = 0;
    for (const auto& entry : path) {
        int i = entry.first;
        const vector<int>& v = entry.second;
        bool f = false;
        
        for (int j : v) {
            if (hp[i] <= hp[j]) {
                f = true;
                break;
            }
        }
        
        if (!f) {
            c++;
        }
    }
    
    cout << c << endl;
    return 0;
}

// <END-OF-CODE>
