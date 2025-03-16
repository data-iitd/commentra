#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <sstream>
#include <map>
#include <cassert>
#include <queue>
#include <array>
#include <set>
#include <bitset>
#include <stack>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c = 0;

    if (a == 1 && b == 1) {
        cout << 0 << endl;
    } else {
        while (a >= 1 || b >= 1) {
            if (a >= b) {
                b++;
                a -= 2;
            } else {
                a++;
                b -= 2;
            }
            if (a <= 0 || b <= 0) {
                c++;
                break;
            }
            c++;
        }
        cout << c << endl;
    }

    return 0;
}
