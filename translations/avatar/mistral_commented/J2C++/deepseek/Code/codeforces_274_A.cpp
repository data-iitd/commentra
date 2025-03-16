#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long k;
    cin >> n >> k;

    vector<long> arr(n);
    set<long> set;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

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

