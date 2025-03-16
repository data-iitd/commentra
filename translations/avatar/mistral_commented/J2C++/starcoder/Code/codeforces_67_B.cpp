
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <utility>
#include <functional>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <cstdarg>
#include <typeinfo>
#include <bitset>
#include <csignal>
#include <ctime>
#include <clocale>
#include <cerrno>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
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
#include <cassert>
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
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cassert>
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
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main ( ) {
  int n = 0 ;
  int k = 0 ;
  int *bb = new int [ n ] ;
  for ( int i = 0 ; i < n ; i ++ ) {
    cin >> bb [ i ] ;
  }
  int *aa = new int [ n ] ;
  int m = 0 ;
  for ( int a = n - 1 ; a >= 0 ; a -- ) {
    int j = 0 ;
    while ( bb [ a ] > 0 ) {
      if ( aa [ j ] >= a + k ) {
        bb [ a ] -- ;
      }
      j ++ ;
    }
    for ( int j_ = m ++ ; j_ > j ; j_ -- ) {
      aa [ j_ ] = aa [ j_ - 1 ] ;
    }
    aa [ j ] = a ;
  }
  for ( int i = 0 ; i < n ; i ++ ) {
    cout << aa [ i ] + 1 << " " ;
  }
  cout << endl ;
  return 0 ;
}

