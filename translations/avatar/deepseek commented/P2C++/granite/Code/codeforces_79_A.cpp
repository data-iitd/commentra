

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int a = 0;
    while (x >= 0 && y >= 22 || x >= 1 && y >= 12 || x >= 2 && y >= 2) {
        if (a) {
            if (y >= 22) {
                y -= 22;
            } else if (x >= 1 && y >= 12) {
                x -= 1;
                y -= 12;
            } else {
                x -= 2;
                y -= 2;
            }
        } else {
            if (x >= 2 && y >= 2) {
                x -= 2;
                y -= 2;
            } else if (x >= 1 && y >= 12) {
                x -= 1;
                y -= 12;
            } else {
                y -= 22;
            }
        }
        a = 1 - a;
    }
    cout << (a? "Ciel" : "Hanako") << endl;
    return 0;
}

