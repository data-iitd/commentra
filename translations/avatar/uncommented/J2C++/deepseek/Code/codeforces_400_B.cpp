#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> arrs(n);
    for (int i = 0; i < n; i++) {
        cin >> arrs[i];
    }

    vector<int> length(n);
    int index = 0;
    for (const string& tmp : arrs) {
        int dexG = tmp.find("G");
        int dexS = tmp.find("S");
        if (dexG > dexS) {
            cout << -1 << endl;
            return 0;
        }
        length[index++] = dexS - dexG;
    }

    set<int> set;
    for (int len : length) {
        set.insert(len);
    }

    cout << set.size() << endl;

