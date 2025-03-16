#include <iostream>
#include <string>
#include <map>
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
    return 0;
}

static map<int, int> str2List(string str) {
    string vArrStr[1000];
    int key = 0;
    map<int, int> ret;
    for (string val : str.split(" ")) {
        ret[key] = atoi(val.c_str());
        key++;
    }
    return ret;
}

