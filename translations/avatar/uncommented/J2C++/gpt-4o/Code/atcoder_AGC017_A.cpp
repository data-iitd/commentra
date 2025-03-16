#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <limits>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cfloat>
#include <complex>
#include <iterator>
#include <sstream>
#include <fstream>
#include <list>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <forward_list>
#include <regex>
#include <valarray>
#include <chrono>
#include <random>
#include <iomanip>
#include <bitset>
#include <exception>
#include <stdexcept>
#include <typeinfo>
#include <typeindex>
#include <type_traits>
#include <initializer_list>
#include <memory>
#include <shared_mutex>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <future>
#include <atomic>
#include <locale>
#include <codecvt>
#include <filesystem>
#include <variant>
#include <any>
#include <optional>
#include <span>
#include <ranges>
#include <concepts>
#include <numbers>
#include <format>

using namespace std;

class Main {
public:
    static __int128_t C(int n, int m) {
        __int128_t res = 1;
        for (int i = m - n + 1; i <= m; i++) {
            res *= i;
        }
        for (int i = 1; i <= n; i++) {
            res /= i;
        }
        return res;
    }

    static void solve() {
        int n, p;
        int k0 = 0, k1 = 0;
        cin >> n >> p;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2 == 1) k1++;
            else k0++;
        }
        __int128_t ans = 1;
        for (int i = 0; i < k0; i++) {
            ans *= 2;
        }
        if (p == 0) {
            __int128_t add = 0;
            for (int i = 0; i <= k1; i += 2) {
                add += C(i, k1);
            }
            ans *= add;
            cout << ans << endl;
        } else {
            __int128_t add = 0;
            for (int i = 1; i <= k1; i += 2) {
                add += C(i, k1);
            }
            ans *= add;
            cout << ans << endl;
        }
    }
};

int main() {
    Main::solve();
    return 0;
}
