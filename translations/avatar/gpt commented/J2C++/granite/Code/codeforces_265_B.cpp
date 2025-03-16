
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = arr[0] + 1;
    for (int i = 1; i < n; i++) {
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }
    cout << ans << endl;
    return 0;
}
