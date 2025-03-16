#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    
    while (n-- > 0) {
        int num;
        cin >> num;
        
        if (m.lower_bound(num) == m.end()) {
            int val = m[num];
            m[num] = ++val;
        } else {
            auto it = m.lower_bound(num);
            --it; // Get the largest key less than num
            int key = it->first;
            int val = it->second;
            
            if (val == 1) {
                m.erase(key);
            } else {
                m[key] = --val;
            }
            int valNum = m[num];
            m[num] = ++valNum;
        }
    }
    
    int ans = 0;
    for (const auto& pair : m) {
        ans += pair.second;
    }
    
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
