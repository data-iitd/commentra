#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <cstdarg>
#include <cerrno>
#include <clocale>
#include <csetjmp>
#include <csignal>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
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
#include <wchar.h>
#include <wctype.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)(v).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fill(a,v) memset(a,v,sizeof(a))
#define sqr(x) ((x)*(x))
#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-9
#define bitcount __builtin_popcount
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define repd(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define repd1(i,n) for(int i=(int)(n);i>0;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fill(a,v) memset(a,v,sizeof(a))
#define sqr(x) ((x)*(x))
#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-9
#define bitcount __builtin_popcount
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define repd(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define repd1(i,n) for(int i=(int)(n);i>0;i--)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<vvpii> vvvpii;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<vvvs> vvvvs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<vvvd> vvvvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;

class FastReader { 
    public: 
        FastReader() { 
            memset(buffer, '\0', sizeof(buffer)); 
            fptr = 0; 
            fin = stdin; 
            buffer[0] = '\0'; 
        } 
        char buffer[1 << 17]; 
        int fptr; 
        FILE *fin; 
        char readChar() { 
            if (fptr == 0) { 
                fptr = fread(buffer, 1, sizeof(buffer) - 1, fin); 
                if (fptr == 0) 
                    return EOF; 
                buffer[fptr] = '\0'; 
            } 
            return buffer[--fptr]; 
        } 
        int readInt() { 
            char c = readChar(); 
            while (c <= 32) 
                c = readChar(); 
            int res = 0; 
            while (c > 32) { 
                res = res * 10 + c - 48; 
                c = readChar(); 
            } 
            return res; 
        } 
        string readString() { 
            char c = readChar(); 
            while (c <= 32) 
                c = readChar(); 
            string res = ""; 
            while (c > 32) { 
                res += c; 
                c = readChar(); 
            } 
            return res; 
        } 
}; 

int main() { 
    FastReader in; 
    int n = in.readInt(); 
    set<int> left; 
    for (int i = 0; i < n; i++) { 
        left.insert(i); 
    } 
    int q = in.readInt(); 
    while (q--) { 
        int l = in.readInt() - 1; 
        int r = in.readInt() - 1; 
        int win = in.readInt(); 
        while (left.size() && *left.begin() <= r) { 
            int curr = *left.begin(); 
            left.erase(left.begin()); 
            printf("%d ", curr + 1); 
        } 
        printf("%d ", win); 
        left.insert(win - 1); 
    } 
    return 0; 
}

