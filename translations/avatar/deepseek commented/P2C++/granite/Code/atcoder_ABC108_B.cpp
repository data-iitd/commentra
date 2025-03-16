
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> p;
    string s;
    while (getline(cin, s)) {
        p.push_back(s);
    }
    int x1 = stoi(p[0]);
    int y1 = stoi(p[1]);
    int x2 = stoi(p[2]);
    int y2 = stoi(p[3]);
    int DIF1 = x2 - x1;
    int DIF2 = y2 - y1;
    int x3 = x2 - DIF2;
    int y3 = y2 + DIF1;
    int x4 = x1 - DIF2;
    int y4 = y1 + DIF1;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}

