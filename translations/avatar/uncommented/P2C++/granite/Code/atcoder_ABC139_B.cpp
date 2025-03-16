
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <cctype>
#include <utility>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int hole = 1;
    int i = 0;
    bool check = true;
    while (check) {
        if (hole >= b) {
            check = false;
        } else {
            hole = a * (i + 1) - i;
            i++;
        }
    }
    cout << i << endl;
    return 0;
}

