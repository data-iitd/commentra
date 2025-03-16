
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<int> a(x * y), b(x * y), c(z), ab, abc;

    for (int i = 0; i < x * y; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < x * y; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < z; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < x * y; i++) {
        for (int j = 0; j < x * y; j++) {
            ab.push_back(a[i] + b[j]);
        }
    }

    sort(ab.begin(), ab.end(), greater<int>());

    for (int i = 0; i < min(k, x * y); i++) {
        for (int j = 0; j < z; j++) {
            abc.push_back(ab[i] + c[j]);
        }
    }

    sort(abc.begin(), abc.end(), greater<int>());

    for (int i = 0; i < k; i++) {
        cout << abc[i] << endl;
    }

    return 0;
}
