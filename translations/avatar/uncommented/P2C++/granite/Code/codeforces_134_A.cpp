
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <random>
#include <valarray>
#include <fstream>
#include <complex>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <ciso646>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

int main ( ) {
    int n;
    cin >> n;
    vector < int > w ( n );
    for ( int i = 0; i < n; i++ ) {
        cin >> w [ i ];
    }
    int x = accumulate ( w.begin ( ), w.end ( ), 0 );
    vector < int > d;
    for ( int i = 0; i < n; i++ ) {
        if ( ( x - w [ i ] ) / ( n - 1 ) == w [ i ] ) {
            d.push_back ( i + 1 );
        }
    }
    cout << d.size ( ) << endl;
    for ( int i = 0; i < d.size ( ); i++ ) {
        cout << d [ i ] << " \n" [ i == d.size ( ) - 1 ];
    }
    return 0;
}
