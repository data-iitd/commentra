#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    long k;
    long arr[100000];
    set<long> set;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % k != 0) {
            count++;
            set.insert(arr[i]);
        } else if (set.find(arr[i] / k) == set.end()) {
            count++;
            set.insert(arr[i]);
        }
    }

    cout << count << endl;

    return 0;
}

