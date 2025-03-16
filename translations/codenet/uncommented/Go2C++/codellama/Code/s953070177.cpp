
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <array>
#include <functional>
#include <cctype>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *aa = new int[n + 2];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> aa[i + 1];
        sum += abs(aa[i + 1] - aa[i]);
    }
    sum += abs(aa[n + 1] - aa[n]);

    for (int i = 1; i < n + 1; i++) {
        int ans = sum - abs(aa[i + 1] - aa[i]) - abs(aa[i] - aa[i - 1]) + abs(aa[i + 1] - aa[i - 1]);
        cout << ans << endl;
    }
    return 0;
}

