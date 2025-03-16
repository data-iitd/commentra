
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
    while (getline(tt, s,'')) {
        int n = stoi(s);
        if (m[n] == 1) {
            m.erase(n);
        } else {
            m[n]--;
        }
    }

    vector<int> result;
    for (auto it = m.begin(); it!= m.end(); it++) {
        result.push_back(it->first);
    }
    sort(result.begin(), result.end());

    PrintList(result);

    return 0;
}

