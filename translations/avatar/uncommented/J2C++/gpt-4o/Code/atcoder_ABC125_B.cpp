#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

map<int, int> str2List(const string& str) {
    map<int, int> ret;
    stringstream ss(str);
    string val;
    int key = 0;
    while (ss >> val) {
        ret[key++] = stoi(val);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline after the integer input
    string vStr;
    getline(cin, vStr);
    map<int, int> vList = str2List(vStr);
    string cStr;
    getline(cin, cStr);
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

// <END-OF-CODE>
