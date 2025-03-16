
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;

typedef long long LL;

class RemRing {
public:
    RemRing(LL module) : module(module) {}
    LL sum(LL a, LL b) { return (a + b + module) % module; }
    LL sub(LL a, LL b) { return (a - b + module) % module; }
    LL prod(LL a, LL b) { return (a * b) % module; }
    LL div(LL a, LL b) { return (a * inv(b)) % module; }
    LL inv(LL a) {
        LL b = module;
        LL u = 1;
        LL v = 0;
        while (b > 0) {
            LL t = a / b;
            a -= t * b;
            u -= t * v;
            swap(a, b);
            swap(u, v);
        }
        u %= module;
        if (u < 0) u += module;
        return u;
    }
private:
    LL module;
};

int main() {
    string s;
    getline(cin, s);
    RemRing ring(100000007);
    cout << char(s[0] + 1) << endl;
    return 0;
}
// END-OF-CODE