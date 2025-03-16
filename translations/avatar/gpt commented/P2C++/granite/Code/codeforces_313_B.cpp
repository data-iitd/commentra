
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string soz;
    cin >> soz;

    int n = soz.length();
    vector<int> a(n + 1, 0);

    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i]) {
            a[i]++;
        }
    }

    int q;
    cin >> q;

    vector<int> arr;
    for (int i = 0; i < q; i++) {
        int m, l;
        cin >> m >> l;
        arr.push_back(a[l - 1] - a[m - 1]);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
