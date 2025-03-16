
#include <bits/stdc++.h>
using namespace std;

// Function to check if 'k' is positive after checking all elements in 'lis' with mid as divisor
bool check(vector<int> lis, int k, int mid) {
    // Iterate through each element in the vector 'lis'
    for (int i : lis) {
        // If the element 'i' is divisible by'mid', increment 'k'
        if (i % mid == 0) {
            k += 1;
        }
        // Subtract the quotient of 'i' and'mid' from 'k'
        k -= (i / mid);
    }
    // Return true if 'k' is still positive after the loop, else false
    return k >= 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> lis(n);
    for (int i = 0; i < n; i++) {
        cin >> lis[i];
    }
    int a = 1, b = *max_element(lis.begin(), lis.end());
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

