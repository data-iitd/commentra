
#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int main() {
    int n;
    string vStr, cStr;
    map<int, int> vList, cList;
    int max = 0;

    cin >> n;
    cin >> vStr;
    stringstream vStream(vStr);
    int key = 0;
    while (vStream >> vList[key]) {
        key++;
    }

    cin >> cStr;
    stringstream cStream(cStr);
    key = 0;
    while (cStream >> cList[key]) {
        key++;
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

