
#include <iostream>
#include <iomanip>
#include <cmath>
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
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <type_traits>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

int main() {
    double N, d, x;
    cin >> N >> d >> x;

    double ans = 0.0;

    while (N > 0.5) {
        double adnum = d + x * (N - 0.5);
        ans += adnum;

        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;

        --N;
    }

    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}

