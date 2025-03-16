#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> items(n);

    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    sort(items.begin(), items.end());

    bool happyAlex = false;

    for (int i = 0; i < n - 1; i++) {
        if (items[i].second > items[i + 1].second) {
            happyAlex = true;
            break;
        }
    }

    if (happyAlex) {
        cout << "Happy Alex" << endl;
    } else {
        cout << "Poor Alex" << endl;
    }

    return 0;
}
