#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Unused variable error avoidance
    a[0] = 0;

    int sum = k;
    int ans = 1;
    while (sum < n) {
        sum = sum - 1 + k;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

