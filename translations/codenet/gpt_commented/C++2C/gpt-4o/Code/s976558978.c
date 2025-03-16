/*
URL_HERE
*/

/*
This section includes necessary headers and defines various constants and macros.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// File pointers for input and output
FILE* _fin = stdin;
FILE* _fout = stdout;

// Mathematical constants and limits
#define PI 3.141592653589793238462643383279502884197169399375105820974
#define ten5p1 100001
#define ten6p1 1000001
#define ten8p1 100000001
#define ten9p1 1000000001

// Type definitions for convenience
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

// Macros for loop iterations
#define rep(var,n) for(int var=0;var<n;++var)

// Macros for min and max operations
#define _min(a,b) ((a)<(b)?(a):(b))
#define _max(a,b) ((a)>(b)?(a):(b))

// Macros for initializing arrays
#define zeroi(data,n) memset(data,0,sizeof(int)*n)
#define zeroll(data,n) memset(data,0,sizeof(long long)*n)
#define one(data,n) {for(int _ONEI=0;_ONEI<n;++_ONEI) data[_ONEI]=1;}

// Functions for reading input
char readc() { char var; fscanf(_fin, "%c", &var); return var; }
int readi() { int var; fscanf(_fin, "%d", &var); return var; }
ll readll() { ll var; fscanf(_fin, "%lld", &var); return var; }

// Function to read an array of integers
void repread(int* data, int n) { rep(i,n) data[i] = readi(); }

// Function to read an array of long long integers
void repreadll(ll* data, int n) { rep(i,n) data[i] = readll(); }

// Function to read a string, ignoring empty lines
int reads(char* str, int maxsize)
{
	for (;;) { 
        if (fgets(str, maxsize, _fin) == NULL) break; 
        if (str[0] != '\n' && str[0] != '\r') break; 
    }
	int slen = strlen(str); 
    if (slen == 0) return 0;
	if (str[slen - 1] == '\n' || str[slen - 1] == '\r') str[--slen] = 0;
	return slen;
}

// Macros for writing output
#define writec(var) fprintf(_fout,"%c",var)
#define writecsp(var) fprintf(_fout,"%c ",var)
#define writecln(var) fprintf(_fout,"%c\n",var)
#define writei(var) fprintf(_fout,"%d",var)
#define writeisp(var) fprintf(_fout,"%d ",var)
#define writellsp(var) fprintf(_fout,"%lld ",var)
#define writeiln(var) fprintf(_fout,"%d\n",var)
#define writellln(var) fprintf(_fout,"%lld\n",var)
#define writeulln(var) fprintf(_fout,"%llu\n",var)
#define writefln(var) fprintf(_fout,"%f\n",var)
#define writes(str) fprintf(_fout,"%s",str)
#define writesp() fprintf(_fout," ")
#define writeln() fprintf(_fout,"\n")

// Macro to check if a number is even
#define iseven(x) ((x&1)==0 ? 1:0)

// Macro to run local tests with a specified input file
#define RUN_LOCAL(testfilename) {_fin = fopen(testfilename, "r"); if(_fin==NULL) _fin=stdin;}

// Function to compute the greatest common divisor (GCD)
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }

// Function for binary search in a sorted array
int bsearch(int val, int* data, int n) { 
    if (data[0] > val) return -1; 
    if (data[n - 1] < val) return n; 
    int l = 0; 
    int r = n - 1; 
    for (; l < r;) { 
        int mid = (l + r + 1) >> 1; 
        if (data[mid] <= val) l = mid; 
        else r = mid - 1; 
    }
    if (data[r] != val) ++r; 
    return r; 
}

// Function to compute modular exponentiation
ll expmod(ll x, ll n, ll m) {
	ll ans = 1;
	for (;n;) {
		if (n & 1) ans = (ans * x) % m; // If n is odd, multiply x with result
		x = (x * x) % m; // Square x
		n >>= 1; // Divide n by 2
	}
	return ans; // Return the result
}

// Function to compute combinations modulo m
ll combmod(ll n, ll k, ll m) {
	ll ret = 1; // Result of n choose k
	ll div = 1; // Denominator for combinations
	for (ll i = 0; i < k; ++i) {
		ret = (ret * (n - i) % m) % m; // Numerator
		div = (div * (i + 1)) % m; // Denominator
	}
	div = expmod(div, m - 2, m) % m; // Modular inverse of denominator
	return (ret * div) % m; // Return the result
}

//------------

int main()
{
	// Run local test with specified input file
	RUN_LOCAL("dataabc155A.txt");

	// Read two integers from input
	int a = readi();
	int b = readi();

	// Output the smaller integer b times
	if (a < b)
	{
		rep(i,b) writei(a); // Write 'a' b times
		writeln(); // New line after output
	}
	else
	{
		rep(i,a) writei(b); // Write 'b' a times
		writeln(); // New line after output
	}
	
	return 0; // End of program
}

/* <END-OF-CODE> */
