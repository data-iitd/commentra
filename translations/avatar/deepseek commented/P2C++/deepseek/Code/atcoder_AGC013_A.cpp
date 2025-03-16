#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <complex>
#include <numeric>
#include <functional>
#include <climits>
#include <bitset>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <iterator>
#include <limits>
#include <new>
#include <stdexcept>
#include <streambuf>
#include <utility>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <clocale>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <utility>
#include <cassert>
#include <cmath>
#include <functional>
#include <typeinfo>
#include <array>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <complex>
#include <numeric>
#include <functional>
#include <climits>
#include <bitset>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <iterator>
#include <limits>
#include <new>
#include <stdexcept>
#include <streambuf>
#include <utility>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <clocale>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Removing consecutive duplicates from vector A
    A.erase(unique(A.begin(), A.end()), A.end());
    // Updating N to reflect the new length of A
    N = A.size();

    // Initializing variables for main logic
    int i = 1;
    int ans = 0;

    // Main logic to find peaks
    while (i < N - 1) {
        if (A[i - 1] < A[i] && A[i] > A[i + 1] || A[i - 1] > A[i] && A[i] < A[i + 1]) {
            ans += 1;
            i += 1;  // Skip next element as it's already checked
        }
        i += 1;
    }

    // Output the total number of peaks found
    cout << ans + 1 << '\n';

    return 0;
}
