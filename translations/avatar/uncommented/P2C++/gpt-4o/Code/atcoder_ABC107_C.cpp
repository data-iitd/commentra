#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int check(int k, const vector<int>& lst_p, const vector<int>& lst_m, int lastx, int lasty) {
    int ans = INT_MAX;
    for (int j = 0; j <= k; j++) {
        if (j > lastx || k - j > lasty) {
            continue;
        } else {
            int p = (j == 0) ? 0 : lst_p[j - 1];
            int m = (k - j == 0) ? 0 : lst_m[lasty - (k - j)];
            ans = min(ans, 2 * p + abs(m));
            ans = min(ans, p + 2 * abs(m));
        }
    }
    return ans;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> lst(N);
    vector<int> lst_p, lst_m;

    for (int i = 0; i < N; i++) {
        cin >> lst[i];
        if (lst[i] == 0) {
            K--;
        }
        if (lst[i] > 0) {
            lst_p.push_back(lst[i]);
        } else if (lst[i] < 0) {
            lst_m.push_back(lst[i]);
        }
    }

    int lastx = lst_p.size();
    int lasty = lst_m.size();

    cout << check(K, lst_p, lst_m, lastx, lasty) << endl;

    return 0;
}

// <END-OF-CODE>
