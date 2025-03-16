
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
    int n;
    string vStr, cStr;
    map<int, int> vList, cList;
    int max = 0;

    cin >> n;
    cin >> vStr;
    stringstream vStream(vStr);
    int v;
    while (vStream >> v) {
        vList[vList.size()] = v;
    }

    cin >> cStr;
    stringstream cStream(cStr);
    int c;
    while (cStream >> c) {
        cList[cList.size()] = c;
    }

    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }

    cout << max << endl;

    return 0;
}

