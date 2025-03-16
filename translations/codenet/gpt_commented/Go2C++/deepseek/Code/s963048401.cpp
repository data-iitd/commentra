#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    vector<int> xs;
    xs.push_back(as[0]);

    for (int j = 1; j < n; j++) {
        int idx = lower_bound(xs.begin(), xs.end(), as[j]) - xs.begin();
        if (idx == xs.size()) {
            xs.push_back(as[j]);
        } else {
            xs[idx] = as[j];
        }
    }

    cout << xs.size() << endl;

    return 0;
}

