
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int sa = count(istream_iterator<char>(cin), istream_iterator<char>(), '-');
    sa = min({n - sa, sa});
    vector<string> ss;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        b -= a;
        ss.push_back((b % 2 && b <= sa * 2)? "1\n" : "0\n");
    }
    cout << accumulate(ss.begin(), ss.end(), string());
    return 0;
}
//END-OF-CODE