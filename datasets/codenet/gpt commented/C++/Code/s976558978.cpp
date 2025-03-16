/*
URL_HERE
*/

/*
This section includes necessary headers and defines various constants and macros.
*/
#ifdef _WIN32
#pragma warning(disable:4996) // Disable specific warnings for Windows
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <iostream>

using namespace std;

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
#define uint unsigned int
#define ll long long
#define ull unsigned long long

// Macros for loop iterations
#define rep(var,n) for(int var=0;var<n;++var)
#define repi(n) rep(i,n)
#define repj(n) rep(j,n)
#define repi1(n) for(int i=1;i<n;++i)
#define repj1(n) for(int j=1;j<n;++j)

// Macros for min and max operations
#define _min(a,b) (a)<(b)?(a):(b)
#define _max(a,b) (a)>(b)?(a):(b)

// Macros for initializing arrays
#define zeroi(data,n) memset(data,0,sizeof(int)*n);
#define zeroll(data,n) memset(data,0,sizeof(long long)*n);
#define one(data,n) {for(int _ONEI=0;_ONEI<n;++_ONEI) data[_ONEI]=1;}

// Functions for reading input
char readc() { char var; fscanf(_fin, "%c", &var); return var; }
int readi() { int var; fscanf(_fin, "%d", &var); return var; }
ll readll() { ll var; fscanf(_fin, "%lld", &var); return var; }

// Function to read an array of integers
void repread(int* data, int n) { repi(n) data[i] = readi(); }

// Function to read an array of long long integers
void repread(ll* data, int n) { repi(n) data[i] = readll(); }

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

// Macros for swapping values
#define swap(type,a, b) {type t=a;a=b;b=t;}
#define swapxor(a,b) {a^=b;b^=a;a^=b;}

// Macro for sorting an array
#define sort(data,n) std::sort(data,data+n)

// Macro for modular arithmetic
#define mod(a,b) b==0 ? 0 : a==0 ? 0 :(a>0 ? a%b : b + a % b)

// Function to compute the greatest common divisor (GCD)
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }

// Function to reverse an array of integers
void reversei(int* data, int n) { 
    int k = n >> 1; 
    repi(k) { 
        int tmp = data[i]; 
        data[i] = data[n - i - 1]; 
        data[n - i - 1] = tmp; 
    } 
}

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

// Macro to define a dynamic array structure
#define _Vec(type, name) \
struct name { type* data; int size; int n; };\
void init(name* t, int size) { t->data = (type*)malloc(sizeof(type) * size); t->size = size; t->n = 0; }\
void resize(name* t) { int ns = t->size * 1.2f; t->data = (type*)realloc(t->data, sizeof(type) * ns); t->size = ns; }\
void add(name* t, type val) { if (t->n >= t->size) resize(t); int k = t->n; t->data[k] = val; t->n = k + 1; }\
void free(name* t) { free(t->data);}

// Define dynamic array structures for integers, long longs, and strings
_Vec(int, Veci)
_Vec(long long, Vecll)
_Vec(char*, Vecs)

// Macro to check if two arrays are palindromes
#define _ispal(type, name) int name(type* a, type* b, int n){repi(n){if (a[i] != b[n - i - 1]){return 0;}}return 1;}
_ispal(int, ispali)
_ispal(char, ispalc)

// Macro to define a pair structure and comparison functions
#define _Pair(type, name) struct name{type x, y;}; \
int cmp_##name(const void* _a, const void* _b){name* a = (name*)_a;name* b = (name*)_b;if (a->x == b->x){if (a->y < b->y) return -1;else return 1;}if (a->x < b->x) return -1;else return 1;}\
void sort_##name(name* d, int n){qsort(d, n, sizeof(name), cmp_##name);}
_Pair(int, Pairi)

// Function to compare strings for sorting
int cmp_Str(const void* _a, const void* _b) { 
    char* a = *((char**)_a); 
    char* b = *((char**)_b); 
    return strcmp(a, b); 
}

// Function to sort an array of strings
void sort_Str(char** str, int n) { 
    qsort(str, n, sizeof(char*), cmp_Str); 
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
		repi(b) writei(a); // Write 'a' b times
		writeln(); // New line after output
	}
	else
	{
		repi(a) writei(b); // Write 'b' a times
		writeln(); // New line after output
	}
	
	return 0; // End of program
}
