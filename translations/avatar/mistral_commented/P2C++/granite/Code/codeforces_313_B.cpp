
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string soz;
    cin >> soz;

    int n;
    cin >> n;

    vector<int> a(soz.length() + 1, 0);

    for (int i = 1; i < soz.length(); i++) {
        a[i] = a[i - 1];
        if (soz[i - 1] == soz[i]) {
            a[i]++;
        }
    }

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int m, l;
        cin >> m >> l;
        arr.push_back(a[l - 1] - a[m - 1]);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
