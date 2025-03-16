

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string vStr, cStr;
    getline(cin, vStr);
    getline(cin, cStr);

    map<int, int> vList, cList;
    stringstream ss(vStr);
    string v;
    while (getline(ss, v,'')) {
        vList[vList.size()] = stoi(v);
    }
    ss.clear();
    ss.str(cStr);
    string c;
    while (getline(ss, c,'')) {
        cList[cList.size()] = stoi(c);
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }

    cout << max << endl;

    return 0;
}

