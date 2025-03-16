
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array(1001, 0);
    for (int i = 0; i < n; i++) {
        int index;
        cin >> index;
        array[index]++;
    }
    int countMax = *max_element(array.begin(), array.end());
    if (n % 2 == 0) {
        if (countMax <= n / 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (countMax <= n / 2 + 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
