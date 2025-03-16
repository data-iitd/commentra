
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string vStr;
    cin >> vStr;
    map<int, int> vList = str2List(vStr);
    string cStr;
    cin >> cStr;
    map<int, int> cList = str2List(cStr);
    int max = 0;
    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }
    cout << max << endl;
}

map<int, int> str2List(string str) {
    vector<string> vArrStr;
    int key = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] =='') {
            vArrStr.push_back(str.substr(0, i));
            str = str.substr(i + 1);
            i = -1;
            key++;
        }
    }
    vArrStr.push_back(str);
    map<int, int> ret;
    for (string val : vArrStr) {
        ret[key] = stoi(val);
        key++;
    }
    return ret;
}

