#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cctype>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <functional>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <cstdarg>
#include <csignal>
#include <csetjmp>
#include <cstdalign>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <initializer_list>
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
#include <ratio>
#include <regex>
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
    int n, k;
    cin >> n >> k;
    n++;
    int z = 0;
    if (n % k!= 0) {
        z = k - n % k;
    }
    cout << n + z << endl;
    return 0;
}

