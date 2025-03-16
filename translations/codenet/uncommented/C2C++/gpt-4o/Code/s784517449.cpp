#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
int n;

/* 二分探索 */
int binarySearch(int key) {
    int left = 0;
    int right = n;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (key == A[mid]) return 1; /* keyを発見 */
        if (key > A[mid]) left = mid + 1; /* 後半を探索 */
        else right = mid; /* 前半を探索 */
    }
    return 0;
}

int main() {
    int q, k, sum = 0;
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> k;
        if (binarySearch(k))
            sum++;
    }
    cout << sum << endl;
    return 0;
}

// <END-OF-CODE>
