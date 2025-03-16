// by syu
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <cctype>
#include <cassert>
using namespace std;

class Scanner {
public:
    Scanner(istream &in) : in(in) {}
    int Int() { int x; in >> x; return x; }
private:
    istream &in;
};

int main() {
    Scanner sc(cin);
    int n = sc.Int(), k = sc.Int();
    if (n % k == 0) {
        printf("0\n");
    } else {
        printf("1\n");
    }
}

