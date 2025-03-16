

#include <bits/stdc++.h>

using namespace std;

vector<string> ReadLongLines(int times) {
    vector<string> result(times);
    string line;
    for (int i = 0; i < times; i++) {
        getline(cin, line);
        result[i] = line;
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
    vector<int> a = vector<int>();
    stringstream ss(lines[1]);
    string s;
    while (getline(ss, s,'')) {
        a.push_back(stoi(s));
    }
    vector<int> b = vector<int>();
    stringstream tt(lines[3]);
    string t;
    while (getline(tt, t,'')) {
        b.push_back(stoi(t));
    }
    set<int> m(a.begin(), a.end());
    for (int i = 0; i < b.size(); i++) {
        m.insert(b[i]);
    }
    vector<int> result(m.begin(), m.end());
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

