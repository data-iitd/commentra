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
    int returnDex = -1;

    for (const string& tmp : arrs) {
        int dexG = tmp.find("G");
        int dexS = tmp.find("S");

        if (dexG > dexS) {
            returnDex = 0;
            break;
        }

        length[index++] = dexS - dexG;
    }

    set<int> uniqueLengths;
    for (int len : length) {
        if (len >= 0) {
            uniqueLengths.insert(len);
        }
    }

    if (returnDex == 0) {
        cout << returnDex << endl;
    } else {
        cout << uniqueLengths.size() << endl;
    }

    return 0;
}

