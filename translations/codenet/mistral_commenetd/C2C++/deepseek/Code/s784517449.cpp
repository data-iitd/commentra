#include <iostream>
using namespace std;

const int MAX = 1000000;
int A[MAX], n;

bool binarySearch(int key) {
    int left = 0;
    int right = n;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (key == A[mid]) {
            return true;
        }
        if (key > A[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return false;
}

int main() {
    int i, q, k, sum = 0;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> q;
    for (i = 0; i < q; i++) {
        cin >> k;
        if (binarySearch(k)) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}

