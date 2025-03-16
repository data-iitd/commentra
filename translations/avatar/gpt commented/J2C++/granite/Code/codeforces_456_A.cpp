
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int maxA = *max_element(a.begin(), a.end());
    int minB = *min_element(b.begin(), b.end());

    bool happy = false;

    for (int i = 0; i < n; i++) {
        if (a[i] == maxA && b[i] < minB) {
            happy = true;
            break;
        }
    }

    if (happy) {
        cout << "Happy Alex" << endl;
    } else {
        cout << "Poor Alex" << endl;
    }

    return 0;
}
