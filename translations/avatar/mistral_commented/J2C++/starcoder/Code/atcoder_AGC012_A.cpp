
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[3*n];
    for (int i = 0; i < 3*n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+3*n);
    long long int res = 0;
    for (int i = 0; i < n; i++) {
        res += arr[3*n-2-2*i];
    }
    cout << res << endl;
    return 0;
}

