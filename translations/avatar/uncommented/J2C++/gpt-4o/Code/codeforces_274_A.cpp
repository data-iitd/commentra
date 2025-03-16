#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> arr(n);
    set<long long> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % k != 0) {
            count++;
            s.insert(arr[i]);
        } else if (s.find(arr[i] / k) == s.end()) {
            count++;
            s.insert(arr[i]);
        }
    }

    cout << count << endl;
    return 0;
}

// <END-OF-CODE>
