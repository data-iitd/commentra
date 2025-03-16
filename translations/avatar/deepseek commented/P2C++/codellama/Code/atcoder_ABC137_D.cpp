
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> x;
    vector<int> y;

    for (int i = 0; i < n; i++) {
        int day, salary;
        cin >> day >> salary;
        x.push_back(make_pair(-day, -salary));
    }

    sort(x.begin(), x.end());

    for (int i = 0; i < n; i++) {
        int d = -x[i].first;
        int s = -x[i].second;
        int r = m - y.size();

        if (r >= d) {
            y.push_back(s);
        } else {
            y.push_back(s);
            y.erase(y.begin());
        }
    }

    int sum = 0;
    for (int i = 0; i < y.size(); i++) {
        sum += y[i];
    }

    cout << sum << endl;

    return 0;
}

