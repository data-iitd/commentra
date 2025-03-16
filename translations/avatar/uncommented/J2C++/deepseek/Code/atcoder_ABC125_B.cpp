#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> str2List(string str) {
    stringstream ss(str);
    string token;
    vector<int> ret;
    int key = 0;
    while (getline(ss, token, ' ')) {
        ret.push_back(stoi(token));
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

    vector<int> vList = str2List(vStr);
    vector<int> cList = str2List(cStr);

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

