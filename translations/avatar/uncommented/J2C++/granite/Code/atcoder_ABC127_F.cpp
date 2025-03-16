
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string s;
    priority_queue<int, vector<int>, greater<int>> pqmax;
    priority_queue<int> pqmin;
    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;
    while (t--) {
        cin >> s;
        if (s[0] == '2') {
            long long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long long ans1 = min;
            ans1 *= pqmax.size();
            ans1 = sumMax - ans1;
            cout << min << " " << (ans + ans1 + sumb) << endl;
        } else {
            int in;
            cin >> in;
            sumb += stoll(s.substr(2));
            if (in > min) {
                pqmax.push(in);
                sumMax += in;
            } else {
                pqmin.push(in);
                sumMin += in;
            }
            if (pqmin.size() > pqmax.size()) {
                sumMax += pqmin.top();
                sumMin -= pqmin.top();
                pqmax.push(pqmin.top());
                pqmin.pop();
            }
            if (pqmin.size() < pqmax.size()) {
                sumMax -= pqmax.top();
                sumMin += pqmax.top();
                pqmin.push(pqmax.top());
                pqmax.pop();
            }
            min = pqmin.top();
        }
    }
    return 0;
}
//END-OF-CODE