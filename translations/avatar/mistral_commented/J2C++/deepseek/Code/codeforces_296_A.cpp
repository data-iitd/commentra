#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    // Main function to start the program
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> array(1001, 0);
    for (int i = 0; i < n; i++) {
        int index;
        cin >> index;
        array[index]++;
    }

    int countMax = -1;
    for (int i = 1; i < array.size(); i++) {
        if (countMax < array[i]) {
            countMax = array[i];
        }
    }

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
