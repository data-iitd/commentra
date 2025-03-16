#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<int, int> str2List(string str) {
    stringstream ss(str);
    string token;
    map<int, int> ret;
    int key = 0;
    while (getline(ss, token, ' ')) {
        ret[key++] = stoi(token);
    }
    return ret;
}

int main() {
    int n;
    string vStr, cStr;
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading n
    getline(cin, vStr);
    getline(cin, cStr);

    map<int, int> vList = str2List(vStr);
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

