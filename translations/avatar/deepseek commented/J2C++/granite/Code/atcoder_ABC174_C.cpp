
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    int K;
    cin >> K;
    if (K % 2 == 0 || K % 5 == 0) {
        cout << -1 << endl;
    } else if (K % 7 == 0) {
        cout << K / 7 << endl;
    } else {
        cout << K * 9 / 7 << endl;
    }
    return 0;
}
