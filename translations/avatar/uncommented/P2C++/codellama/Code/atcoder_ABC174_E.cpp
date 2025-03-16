
#include <iostream>
using namespace std;

bool check(int lis[], int k, int mid) {
    int count = 0;
    for (int i = 0; i < k; i++) {
        if (lis[i] % mid == 0) {
            count++;
        }
        count -= (lis[i] / mid);
    }
    return count >= 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    int lis[n];
    for (int i = 0; i < n; i++) {
        cin >> lis[i];
    }
    int a = 1, b = lis[n - 1];
    int ans = b;
    while (a <= b) {
        int mid = (a + b) / 2;
        if (check(lis, k, mid)) {
            ans = mid;
            b = mid - 1;
        } else {
            a = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

