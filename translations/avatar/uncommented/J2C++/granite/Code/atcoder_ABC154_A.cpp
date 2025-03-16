
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <list>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string a, b;
    ss >> a >> b;
    string u;
    getline(cin, u);
    if (u == a) {
        cout << a << " " << b - 1 << endl;
    } else {
        cout << a - 1 << " " << b << endl;
    }
    return 0;
}
//END-OF-CODE