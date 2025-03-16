#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);

    for (int i = 0; i < n; i++) {
        cin >> ab[i].first >> ab[i].second;
    }

    sort(ab.begin(), ab.end());

    bool happy_alex = false;

    for (int i = 0; i < n - 1; i++) {
        if (ab[i].second > ab[i + 1].second) {
            happy_alex = true;
            break;
        }
    }

    if (happy_alex) {
        cout << "Happy Alex" << endl;
    } else {
        cout << "Poor Alex" << endl;
    }

    return 0;
}

