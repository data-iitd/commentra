#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    vector<int> l2;
    for (int i : l) {
        if (i % m == 0) {
            l2.push_back(i / m);
        } else {
            l2.push_back(i / m + 1);
        }
    }

    int mx = *max_element(l2.begin(), l2.end());

    int ind = 0;
    for (int i = 0; i < n; ++i) {
        if (l2[i] == mx) {
            ind = i;
            break;
        }
    }

    cout << ind + 1 << endl;

    return 0;
}

