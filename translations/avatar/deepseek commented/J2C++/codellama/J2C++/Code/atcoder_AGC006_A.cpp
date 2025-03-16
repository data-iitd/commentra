
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <algorithm> 
#include <cmath> 
#include <vector> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <string> 
#include <cctype> 
#include <fstream> 
#include <sstream> 
#include <cassert> 
#include <ctime> 
#include <cmath> 
#include <bitset> 
#include <iomanip> 
#include <utility> 
using namespace std ; 

#define MOD 1000000007 
#define all(x) (x).begin(), (x).end() 
#define sz(x) ((int)(x).size()) 
#define pb push_back 
#define mp make_pair 
#define ln length 
#define INF 1000000000 
#define INFLL 1000000000000000000LL 
#define INT_MAX 2147483647 
#define INT_MIN (-2147483647-1) 
#define pi acos(-1.0) 
#define N 2000000000 
#define eps 1e-9 
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679 

int f [ N ] ; 
char b [ N ] ; 

// Computes the failure array for the given pattern
void getFail ( char b [ ] , int m ) { 
    int j = 0 ; 
    f [ 0 ] = f [ 1 ] = 0 ; 
    for ( int i = 2 ; i <= m ; i ++ ) { 
        while ( j > 0 && b [ j + 1 ] != b [ i ] ) 
            j = f [ j ] ; 
        if ( b [ j + 1 ] == b [ i ] ) 
            j ++ ; 
        f [ i ] = j ; 
    } 
} 

int main ( ) { 
    // Read input values
    int n ; 
    string s1 , str ; 
    cin >> n >> s1 >> str ; 
    
    // Construct a combined string
    int cnt = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ) 
        b [ ++ cnt ] = str [ i ] ; 
    for ( int i = 0 ; i < n ; i ++ ) 
        b [ ++ cnt ] = s1 [ i ] ; 
    
    // Compute the failure array for the combined string
    getFail ( b , cnt ) ; 
    
    // Calculate the result based on the failure array
    int len = min ( f [ cnt ] , min ( n , n ) ) ; 
    
    // Print the result
    cout << 2 * n - len << endl ; 
    
    return 0 ; 
} 

