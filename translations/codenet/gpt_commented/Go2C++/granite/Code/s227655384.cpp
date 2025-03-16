
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

vector<string> ReadLongLines(int times) {
    vector<string> result;
    string line;
    for (int i = 0; i < times; i++) {
        getline(cin, line);
        result.push_back(line);
    }
    return result;
}

void PrintList(vector<int> list) {
    for (int i = 0; i < list.size(); i++) {
        if (i == 0) {
            cout << list[i];
        } else {
            cout << " " << list[i];
        }
    }
    cout << endl;
}

int main() {
    vector<string> lines = ReadLongLines(4);
    map<int, int> m;
    stringstream ss(lines[1]);
    string s;
    while (getline(ss, s,'')) {
        int n = stoi(s);
        m[n]++;
    }
    stringstream tt(lines[3]);
    vector<int> result;
    while (getline(tt, s,'')) {
        int n = stoi(s);
        if (m[n] > 0) {
            m[n]--;
        } else {
            result.push_back(n);
        }
    }
    for (auto it = m.begin(); it!= m.end(); it++) {
        if (it->second > 0) {
            result.push_back(it->first);
        }
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

