#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int arr[26] = {0};
    for (int i = 0; i < n; i++) {
        arr[s[i] - 'A']++;
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        sort(arr, arr + 26);
        int change = min(arr[25], k - i);
        ans += change * change;
        arr[25] -= change;
        i += change - 1;
    }
    cout << ans << "\n";
    return 0;
}

