#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cassert>
#include <utility>
#include <bitset>
using namespace std;

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;
    double kaku, mkaku, hkaku, ans2, AA, BB, AA2, BB2, CC, DD, dkaku, dans2;
    mkaku = M * 6;
    hkaku = H * 30 + (double)M / 2;
    kaku = mkaku - hkaku;
    dkaku = abs(kaku * 3.14159265358979323846 / 180);
    AA = A * A;
    BB = B * B;
    AA2 = AA + BB;
    BB2 = AA * BB;
    CC = sqrt(AA2 + BB2 - 2 * AA * BB * cos(dkaku));
    DD = sqrt(AA2 + BB2);
    ans2 = CC - DD;
    dans2 = ans2 * ans2;
    cout << fixed << setprecision(10) << sqrt(dans2) << endl;
    return 0;
}

