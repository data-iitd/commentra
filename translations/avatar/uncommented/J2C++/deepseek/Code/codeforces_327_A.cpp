#include <iostream>
#include <vector>
using namespace std;

int checkNo(const vector<int>& brr) {
    int val = 0;
    for (int i : brr) if (i == 1) ++val;
    return val;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> brr = arr;
            for (int k = i; k <= j; k++) {
                brr[k] = (brr[k] == 0) ? 1 : 0;
            }
            int count = checkNo(brr);
            if (count > max) max = count;
        }
    }
    if (n == 1) {
        cout << (arr[0] == 1 ? 0 : 1) << endl;
    } else {
        cout << max << endl;
    }
    return 0;
}
