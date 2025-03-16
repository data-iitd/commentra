#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, goal;
    cin >> n >> goal;
    int arr[n-1];
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }
    bool isFound = dfs(1, arr, goal);
    if (isFound) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

