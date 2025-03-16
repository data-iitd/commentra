#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int c = 0;
        stack <char> st;
        for (int i = 0; i < s.length(); i++) {
            st.push(s[i]);
            while (st.size() > 1) {
                char p = st.top();
                st.pop();
                char q = st.top();
                st.pop();
                if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                    c++;
                    continue;
                } else {
                    st.push(q);
                    st.push(p);
                    break;
                }
            }
        }
        cout << c * 2 << "\n";
    }
    return 0;
}
