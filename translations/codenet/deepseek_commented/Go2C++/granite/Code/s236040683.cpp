

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void out(vector<string> x) {
    for (auto s : x) {
        cout << s << endl;
    }
}

vector<string> split(string s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c)) {
        v.push_back(x);
    }
    return v;
}

int main() {
    string s;
    getline(cin, s);
    vector<string> vs = split(s,'');
    int N = stoi(vs[0]), M = stoi(vs[1]);

    vector<vector<int>> n(N);

    for (int i = 0; i < M; i++) {
        getline(cin, s);
        vs = split(s,'');
        int from = stoi(vs[0]) - 1, to = stoi(vs[1]) - 1;
        n[from].push_back(to);
        n[to].push_back(from);
    }

    for (int i = 0; i < N; i++) {
        out({to_string(n[i].size())});
    }

    return 0;
}

