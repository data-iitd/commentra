

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    vector<int> xs = {as[0]};
    for (int j = 1; j < n; j++) {
        auto it = lower_bound(xs.begin(), xs.end(), as[j]);
        if (it == xs.end()) {
            xs.push_back(as[j]);
        } else {
            *it = as[j];
        }
    }

    cout << xs.size() << endl;

    return 0;
}

