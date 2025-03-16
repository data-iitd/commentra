#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<int>& lis, int& k, int mid) {
    for (int i : lis) {
        if (i % mid == 0) {
            k += 1;
        }
        k -= (i / mid);
    }
    return k >= 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> lis(n);
    for (int i = 0; i < n; ++i) {
        cin >> lis[i];
    }

    int a = 1, b = *max_element(lis.begin(), lis.end());
    int ans = b;

    while (a <= b) {
        int mid = (a + b) / 2;
        int tempK = k; // Create a temporary copy of k for the check function
        if (check(lis, tempK, mid)) {
            ans = mid;
            b = mid - 1;
        } else {
            a = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
