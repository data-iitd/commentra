
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

int main() {
    try {
        string s;
        getline(cin, s);
        vector<string> x;
        stringstream ss(s);
        string y;
        while(getline(ss, y,'')) {
            x.push_back(y);
        }
        int a = atoi(x[0].c_str());
        int b = atoi(x[1].c_str());
        int c = a - b * 2;
        if (c < 0) c = 0;
        cout << c << endl;
    } catch (exception &e) {
    }
    return 0;
}
// END-OF-CODE