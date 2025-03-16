#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool all_same(const vector<int>& arr) {
    return all_of(arr.begin(), arr.end(), [&](int x) { return x == arr[0]; });
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> elems(n);
    for (int i = 0; i < n; ++i) {
        cin >> elems[i];
    }

    if (all_same(elems)) {
        cout << 0 << endl;
        return 0;
    }
    if (k == 1) {
        cout << -1 << endl;
        return 0;
    }
    if (!all_same(vector<int>(elems.begin() + k - 1, elems.end()))) {
        cout << -1 << endl;
        return 0;
    }

    int target = elems.back();
    vector<int> to_delete(elems.begin(), elems.begin() + k - 1);
    while (!to_delete.empty() && to_delete.back() == target) {
        to_delete.pop_back();
    }
    cout << to_delete.size() << endl;

    return 0;
}

// <END-OF-CODE>
