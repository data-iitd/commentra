#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iterator>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> li(m);
    for (int i = 0; i < m; ++i) {
        int size;
        cin >> size;
        li[i].resize(size - 1);
        for (int j = 0; j < size - 1; ++j) {
            cin >> li[i][j];
        }
    }
    
    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }
    
    set<int> q;
    for (const auto& vec : li) {
        q.insert(vec.begin(), vec.end());
    }
    
    set<int> r;
    for (int i = 1; i <= n; ++i) {
        r.insert(i);
    }
    
    set<int> v;
    set_difference(r.begin(), r.end(), q.begin(), q.end(), inserter(v, v.end()));
    
    long long ans = 0;
    int q_size = q.size();
    vector<int> q_vec(q.begin(), q.end());
    
    for (int i = 0; i <= q_size; ++i) {
        vector<bool> bitmask(q_size);
        fill(bitmask.begin(), bitmask.begin() + i, true);
        
        do {
            set<int> s;
            for (int j = 0; j < q_size; ++j) {
                if (bitmask[j]) {
                    s.insert(q_vec[j]);
                }
            }
            
            bool valid = true;
            for (int j = 0; j < m; ++j) {
                int count = 0;
                for (const auto& u : li[j]) {
                    if (s.count(u)) {
                        count++;
                    }
                }
                if (count % 2 != p[j]) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                ans += pow(2, v.size());
            }
        } while (next_permutation(bitmask.begin(), bitmask.end()));
    }
    
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
