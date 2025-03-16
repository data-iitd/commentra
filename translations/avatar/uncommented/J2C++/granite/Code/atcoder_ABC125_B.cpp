
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string vStr, cStr;
    getline(cin, vStr);
    getline(cin, cStr);
    vector<int> vList, cList;
    stringstream ss(vStr);
    string item;
    while (getline(ss, item,'')) {
        vList.push_back(stoi(item));
    }
    ss.clear();
    ss.str(cStr);
    while (getline(ss, item,'')) {
        cList.push_back(stoi(item));
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

