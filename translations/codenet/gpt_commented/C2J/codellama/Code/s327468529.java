
#if 0
cat <<EOF >mistaken-paste
#endif
// thx Ebi-chan!

// Suppress warnings for incompatible pointer types
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

// Include necessary headers
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Define constants for large numbers and modular arithmetic
#define BIG 2000000007
#define VERYBIG 20000000000000007LL
#define MOD 1000000007
#define FOD  998244353

// Define types for unsigned and signed long long integers
typedef uint64_t ull;
typedef int64_t sll;

// Define maximum size for arrays
#define N_MAX 1048576

#ifdef __cplusplus
// Include C++ standard library headers if compiling as C++
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <array>

using std::queue;
using std::priority_queue;
using std::stack;
using std::tuple;
using std::set;
using std::map;
using std::vector;
using std::greater;
using std::pair;
using std::string;
using std::get;

// Overload the + operator for pairs
template <typename T, typename U>
pair<T, U> operator+(pair<T, U> l, pair<T, U> r) {
	return pair<T, U>(l.first + r.first, l.second + r.second);
}

#endif

// Define M_PI if not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950
#endif

// Define structures for various data types
typedef struct {
	sll a;
	sll b;
} hwll;

typedef struct {
	sll a;
	sll b;
	sll c;
} hwllc;

typedef struct {
	hwll a;
	hwll b;
} linell;

typedef struct {
	double a;
	double b;
} hwreal;

// Global variables for various parameters
sll n, m; // Dimensions or counts
sll h, w; // Height and width
sll k; // Some parameter
sll q; // Query count
sll va, vb, vc, vd, ve, vf; // Various signed long long variables
ull ua, ub, uc, ud, ue, uf; // Various unsigned long long variables
long double vra, vrb, vrc; // Various long double variables
double vda, vdb, vdc; // Various double variables
char ch, dh; // Character variables

// Function to return the minimum of two unsigned long long integers
ull umin (ull x, ull y) {
	return (x < y) ? x : y;
}

// Function to return the maximum of two unsigned long long integers
ull umax (ull x, ull y) {
	return (x > y) ? x : y;
}

// Function to return the minimum of two signed long long integers
sll smin (sll x, sll y) {
	return (x < y) ? x : y;
}

// Function to return the maximum of two signed long long integers
sll smax (sll x, sll y) {
	return (x > y) ? x : y;
}

// Function to compute the greatest common divisor (GCD) of two unsigned long long integers
ull gcd (ull x, ull y) {
	if (y == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}

// Function to compute a^x mod modulo using binary exponentiation
ull bitpow (ull a, ull x, ull modulo) {
	ull result = 1;
	while (x) {
		if (x & 1) {
			result *= a;
			result %= modulo;
		}
		x /= 2;
		a = (a * a) % modulo;
	}
	return result;
}

// Function to perform modular division a / b mod modulo
ull divide (ull a, ull b, ull modulo) {
	return (a * bitpow(b, modulo - 2, modulo)) % modulo;
}

// Function to return the absolute difference between two unsigned long long integers
ull udiff (ull a, ull b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

// Function to return the absolute difference between two signed long long integers
sll sdiff (sll a, sll b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

// Function to count the number of set bits in an unsigned long long integer
int bitcount (ull n) {
	int result = 0;
	while (n) {
		if (n & 1) result++;
		n /= 2;
	}
	return result;
}

// Macros for comparison functions
#define BEGCMP(NAME) int32_t NAME (const void *left, const void *right)
#define DEFLR(TYPE) TYPE l=*(TYPE*)left,r=*(TYPE*)right
#define CMPRET(L, R) if((L)<(R))return-1;if((L)>(R))return+1

// Comparison function for unsigned long long integers
BEGCMP(pullcomp){
	DEFLR(ull);
	CMPRET(l, r);
	return 0;
}

// Comparison function for signed long long integers in reverse order
BEGCMP(prevcomp){
	DEFLR(sll);
	CMPRET(r, l);
	return 0;
}

// Comparison function for signed long long integers
BEGCMP(psllcomp){
	DEFLR(sll);
	CMPRET(l, r);
	return 0;
}

// Comparison function for characters
BEGCMP(pcharcomp){
	DEFLR(char);
	CMPRET(l, r);
	return 0;
}

// Comparison function for double values
BEGCMP(pdoublecomp){
	DEFLR(double);
	CMPRET(l, r);
	return 0;
}

// Comparison function for strings
int32_t pstrcomp (const void *left, const void *right) {
	char* l = *(char**)left;
	char* r = *(char**)right;

	return strcmp(l, r);
}

// Comparison function for hwll structures based on fields a and b
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}

// Comparison function for hwll structures in reverse order
BEGCMP(phwllREVcomp){
	DEFLR(hwll);
	CMPRET(l.b, r.b);
	CMPRET(l.a, r.a);
	return 0;
}

// Comparison function for hwllc structures based on fields a, b, and c
BEGCMP(ptriplecomp){
	DEFLR(hwllc);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwllc structures in reverse order
BEGCMP(ptripleREVcomp){
	DEFLR(hwllc);
	CMPRET(l.b, r.b);
	CMPRET(l.a, r.a);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwllc structures based on field c, then a, then b
BEGCMP(ptripleCABcomp){
	DEFLR(hwllc);
	CMPRET(l.c, r.c);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}

// Comparison function for hwreal structures based on fields a and b
BEGCMP(phwrealcomp){
	DEFLR(hwreal);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}

// Comparison function for linell structures based on their components
int32_t pquadcomp (const void *left, const void *right) {
	linell l = *(linell*)left;
	linell r = *(linell*)right;

	sll ac = phwllABcomp(&(l.a), &(r.a));
	if (ac) return ac;
	sll bc = phwllABcomp(&(l.b), &(r.b));
	if (bc) return bc;

	return 0;
}

// Comparison function for hwllc structures based on a fraction
int32_t pfracomp (const void *left, const void *right) {
	hwllc l = *(hwllc*)left;
	hwllc r = *(hwllc*)right;

	CMPRET(l.a * r.b, l.b * r.a);
	return 0;
}

// Function to check if a value x is within a range [left, right]
bool isinrange (sll left, sll x, sll right) {
	return (left <= x && x <= right);
}

// Function to check if a value x is within a range [left, right] or vice versa
bool isinrange_soft (sll left, sll x, sll right) {
	return (left <= x && x <= right) || (left >= x && x >= right);
}

// Function to swap two signed long long integers
void sw (sll *l, sll *r) {
	if (*l == *r) return;
	sll t = *l;
	*l = *r;
	*r = t;
}

// Arrays for factorials and their inverses
ull frac[N_MAX * 3], invf[N_MAX * 3];

// Function to compute n choose r modulo m
ull ncr (sll n, sll r, ull m) {
	if (n < 0 || r < 0 || n < r) return 0;
	return frac[n] * (invf[r] * invf[n - r] % m) % m;
}

// Arrays for various data types
sll a[N_MAX + 5];
sll b[N_MAX + 5];
sll c[N_MAX + 5];
sll d[N_MAX + 5];
sll e[N_MAX * 4];
char s[N_MAX + 1];
char t[N_MAX + 1];
char u[N_MAX + 1];
hwll xy[N_MAX + 5];
hwllc tup[N_MAX + 5];
sll table[3005][3005];
ull gin[N_MAX];

// Initialize counters and arrays for computations
sll cnt[3], pcnt;
ull x[3005][3005];

// Function to compute the result
ull solve () {
	sll i, j, ki, li;
	sll result = 0; // Variable to store the result
	sll maybe = 0; // Variable for potential calculations
	sll sum = 0; // Variable for summation
	sll item; // Temporary variable
	sll *dpcell; // Pointer for dynamic cell references

	// Initialize result
	result = 1;

	// Process the input string and calculate the result based on color counts
	for (i = 0; i < n * 3; i++) {
		ull v;
		switch (s[i]) {
		case 'R':
			v = 0; // Red
			break;
		case 'G':
			v = 1; // Green
			break;
		case 'B':
			v = 2; // Blue
			break;
		}

		// Check if there are available colors to form combinations
		if (cnt[(v + 1) % 3] && cnt[(v + 2) % 3]) {
			result *= pcnt; // Multiply by the count of available combinations
			pcnt--; // Decrease the count of available combinations
			result %= FOD; // Apply modulo
			cnt[(v + 1) % 3]--; // Decrease count of the first color
			cnt[(v + 2) % 3]--; // Decrease count of the second color
		} else {
			// If there are more of the other two colors than the current color
			if ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]) {
				result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
				result %= FOD; // Apply modulo
				pcnt++; // Increase the count of available combinations
			}
			cnt[v]++; // Increase count of the current color
		}
	}

	// Calculate the factorial of n for final result
	for (i = 1; i <= n; i++) {
		result = (result * i) % FOD;
	}

	// Output the result
	System.out.println(result);
	return 0;

	success:
	System.out.println("Yes"); // Indicate success
	return 0;

	fail:
	System.out.println("-1"); // Indicate failure
	return 1;
}

// Main function to execute the program
int32_t main (int argc, char *argv[]) {
	int32_t i, j;

	n = 4; // Set initial value for n
	m = 0; // Set initial value for m

	// Read input values
	Scanner sc = new Scanner(System.in);
	n = sc.nextLong();
	m = sc.nextLong();
	s = sc.next(); // Read the string input

	// Call the solve function to compute the result
	solve();

	return 0; // Exit the program
}

