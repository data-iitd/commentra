
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <complex>
#include <utility>
#include <bitset>
#include <functional>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ios>
#include <iosfwd>
#include <locale>
#include <ctime>
#include <limits>
#include <bitset>
#include <complex>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

using namespace std ;

int main ( ) {
    long long N, A, B, k = 0 ;

    cin >> N >> A >> B ;

    if ( 1 <= N && N <= pow ( 10, 18 ) && 0 <= A && 0 <= B && 0 < A + B && A + B <= pow ( 10, 18 ) ) {
        if ( A + B <= N ) {
            k = ( N / ( A + B ) ) ;

            if ( ( N - k * ( A + B ) ) > A ) {
                cout << ( A * k + ( N - k * ( A + B ) ) - ( N - ( k * ( A + B ) + A ) ) ) << endl ;
            } else {
                cout << ( A * k + ( N - k * ( A + B ) ) ) << endl ;
            }
        } else if ( A + B > N && A <= N ) {
            cout << A << endl ;
        } else {
            cout << N << endl ;
        }
    }

    return 0 ;
}

