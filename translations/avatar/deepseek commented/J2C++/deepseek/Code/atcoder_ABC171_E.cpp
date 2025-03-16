#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::accumulate
#include <unordered_set>
#include <set>
#include <queue>
#include <functional>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int r = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r ^= a[i];
    }

    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << (r ^ a[i]);
    }
    cout << endl;

    return 0;
}
