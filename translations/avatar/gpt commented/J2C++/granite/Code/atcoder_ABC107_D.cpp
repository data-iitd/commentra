
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Task {
public:
    int solve(vector<int> &arr) {
        int n = arr.size();
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int target = sorted[mid];
            int cur = 0;
            ll cnt = 0;
            vector<int> bit(2 * n + 2);
            for (int i = 0; i < n; i++) {
                cur += arr[i] <= target? 1 : -1;
                for (int x = cur + n + 1; x < bit.size(); x += x & -x)
                    bit[x]++;
                for (int x = cur + n; x > 0; x -= x & -x)
                    cnt += bit[x];
            }
            if (cnt >= (ll)n * (n + 1) / 4 + 1)
                r = mid;
            else
                l = mid + 1;
        }
        return sorted[l];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Task tsk;
    cout << tsk.solve(arr) << endl;
    return 0;
}

