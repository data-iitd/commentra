#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<int, int> str2List(string str) {
    stringstream ss(str);
    string token;
    map<int, int> ret;
    int key = 0;

    while (getline(ss, token, ' ')) {
        ret[key] = stoi(token);
        key++;
    }

    return ret;
}

int main() {
    string line;
    getline(cin, line);
    int n = stoi(line);

    getline(cin, line);
    map<int, int> vList = str2List(line);

    getline(cin, line);
    map<int, int> cList = str2List(line);

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

