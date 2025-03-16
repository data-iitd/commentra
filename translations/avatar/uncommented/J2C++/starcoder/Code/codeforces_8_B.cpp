#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <climits>
#include <bitset>
using namespace std;

int main() {
    char s[100];
    int x = 0, y = 0, k = 0, dx, dy;
    bool flag = true;
    scanf("%s", s);
    int co[2][101];
    co[0][k] = x;
    co[1][k] = y;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == 'L') --x;
        else if (s[i] == 'R') ++x;
        else if (s[i] == 'U') ++y;
        else if (s[i] == 'D') --y;
        co[0][k] = x;
        co[1][k] = y;
        ++k;
    }
    for (int i = 0; i < k - 3; ++i) {
        for (int j = i + 3; j < k; ++j) {
            dx = co[0][i] - co[0][j];
            dy = co[1][i] - co[1][j];
            if (dx < 0) dx *= -1;
            if (dy < 0) dy *= -1;
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    if (flag) printf("OK\n");
    else printf("BUG\n");
    return 0;
}
