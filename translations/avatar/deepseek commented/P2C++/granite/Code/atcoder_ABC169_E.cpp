
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> low;
    vector<int> high;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        low.push_back(a);
        high.push_back(b);
    }

    sort(low.begin(), low.end());
    sort(high.begin(), high.end());

    if (n % 2) {
        cout << high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1 << endl;
    } else {
        double hh = (high[n / 2 - 1] + high[n / 2]) / 2.0;
        double ll = (low[n / 2 - 1] + low[n / 2]) / 2.0;
        cout << int((hh - ll) * 2) + 1 << endl;
    }

    return 0;
}
