
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {
            vector<int> crt;
            crt.push_back(i);
            int x = a[i];
            while (cnt[x] == 1) {
                crt.push_back(x);
                x = a[x];
            }
            if (crt.size() > ans.size()) {
                ans = crt;
            }
        }
    }
    ans.push_back(ans[0]);
    ans.erase(ans.begin());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

