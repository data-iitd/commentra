#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <valarray>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <chrono>
#include <random>
#include <limits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int main() {
    int A, B, H, M;
    cin >> A >> B >> H >> M;

    double mkaku = M * 6;
    double hkaku = H * 30 + M * 0.5;

    double kaku = fabs(mkaku - hkaku);

    double dkaku = fabs(kaku * M_PI / 180);

    double AA2 = A * A;
    double BB2 = B * B;

    double CC = AA2 + BB2;
    double DD = cos(dkaku) * A * B;

    double ans2 = CC - DD;
    double ans = sqrt(ans2);

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
