
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> ns(4);
    for (int i = 0; i < 4; i++) {
        cin >> ns[i];
    }
    sort(ns.begin(), ns.end());
    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
