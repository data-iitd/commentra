#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> readInts() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    return nums;
}

int main() {
    int n;
    cin >> n;
    vector<int> A = readInts();
    sort(A.begin(), A.end());
    long long ans = 0;
    for (int i = A.size() - 2; i >= A.size() - 2 * n; i -= 2) {
        ans += A[i];
    }
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
