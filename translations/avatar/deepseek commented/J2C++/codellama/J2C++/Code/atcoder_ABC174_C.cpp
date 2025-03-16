#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <set> 
#include <map> 
#include <list> 
#include <queue> 
#include <stack> 
#include <memory> 
#include <iomanip> 
#include <numeric> 
#include <functional> 
#include <new> 
#include <algorithm> 
#include <cmath> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
#include <climits> 
#include <cctype> 
#include <ctime> 

#define REP(i, n) for(int (i) = 0; i < n; i++) 
#define FOR(i, a, n) for(int (i) = a; i < n; i++) 
#define FORR(i, a, n) for(int (i) = a; i <= n; i++) 
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++) 
#define sz(n) n.size() 
#define pb(n) push_back(n) 
#define all(n) n.begin(), n.end() 

template<typename T> T gcd(T a, T b) { 
    if(!b) return a; 
    return gcd(b, a % b); 
} 
template<typename T> T lcm(T a, T b) { 
    return a * b / gcd(a, b); 
} 

using namespace std; 

typedef long long ll; 
typedef long double ld; 

int readInt() { 
    int n = 0; 
    char c = ' '; 
    while(c < '0' || c > '9') c = getchar(); 
    while(c >= '0' && c <= '9') n = n * 10 + c - '0', c = getchar(); 
    return n; 
} 

int solve() { 
    int K = readInt(); 

    // Check if K is divisible by 2 or 5, return -1 if true.
    if(K % 2 == 0 || K % 5 == 0) 
        return -1; 

    // If K is divisible by 7, divide K by 7.
    if(K % 7 == 0) 
        K /= 7; 

    // Multiply K by 9.
    K *= 9; 

    // Initialize the answer and the remainder.
    int ans = 1; 
    int remainder = 10 % K; 

    // Loop to find the number of digits required to form a number that is a multiple of K.
    while(remainder != 1) { 
        ans++; 
        remainder = remainder * 10 % K; 
    } 

    return ans; 
} 

int main() { 
    cout << solve() << endl; 
    return 0; 
} 

