
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    cin >> n;

    vector<int> ll(n);
    for (int i = 0; i < n; i++) {
        cin >> ll[i];
    }

    sort(ll.begin(), ll.end());

    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1, r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            ans += l - (j + 1);
        }
    }

    cout << ans << endl;

    fin.close();
    fout.close();

    return 0;
}

