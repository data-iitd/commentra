#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), num(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    
    for (int i = 1; i <= n; i++) {
        num[b[i]]++;
    }
    
    string ss = "";
    int ans = 0;
    vector<bool> st(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = true;
            string sb = "";
            int x = b[i];
            string sss = to_string(i);
            sb += " " + string(sss.rbegin(), sss.rend());
            int s = 1;
            
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {
                sss = to_string(x);
                sb += " " + string(sss.rbegin(), sss.rend());
                st[x] = true;
                x = b[x];
                s++;
            }
            
            if (s > ans) {
                ans = s;
                ss = string(sb.rbegin(), sb.rend());
            }
        }
    }
    
    cout << ans << endl;
    cout << ss << endl;

    return 0;
}

// <END-OF-CODE>
