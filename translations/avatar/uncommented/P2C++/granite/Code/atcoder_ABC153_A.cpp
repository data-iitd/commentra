
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <cctype>
#include <utility>
using namespace std;

int main() {
    int h, a;
    cin >> h >> a;
    int sho = h / a;
    int am = h % a;
    if (am!= 0) {
        sho += 1;
    }
    cout << sho << endl;
    return 0;
}
