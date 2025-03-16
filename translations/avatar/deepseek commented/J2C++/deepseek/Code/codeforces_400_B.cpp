#include <iostream>
#include <set>
#include <string>
#include <vector>

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
    int returnDex = 0;

    for (const string& tmp : arrs) {
        size_t dexG = tmp.find('G');
        size_t dexS = tmp.find('S');
        if (dexG > dexS) {
            returnDex = -1;
        }
        length[index++] = static_cast<int>(dexS - dexG);
    }

    set<int> set;
    for (int len : length) {
        set.insert(len);
    }

    if (returnDex == -1) {
        cout << returnDex << endl;
    } else {
        cout << set.size() << endl;
    }

    return 0;
}

