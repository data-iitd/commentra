#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <climits>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c = 0;
    cin >> a >> b;
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


