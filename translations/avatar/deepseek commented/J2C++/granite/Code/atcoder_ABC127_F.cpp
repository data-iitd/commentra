
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declare static members for output stream and print writer
    static auto &out = cout;

    int t;
    cin >> t;

    priority_queue<int> pqmax;
    priority_queue<int, vector<int>, greater<int>> pqmin;

    long long sumMin = 0, sumMax = 0, sumb = 0;
    int min = 0;

    while (t--) {
        int cmd;
        cin >> cmd;

        if (cmd == 2) {
            long long ans = min;
            ans *= pqmin.size();
            ans -= sumMin;
            long long ans1 = min;
            ans1 *= pqmax.size();
            ans1 = sumMax - ans1;
            out << min << " " << (ans + ans1 + sumb) << endl;
        } else {
            int in;
            cin >> in;
            sumb += in;

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

