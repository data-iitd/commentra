

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <array>

using namespace std;

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
	return (x < y)? x : y;
}

// Function to return the maximum of two unsigned long long integers
ull umax (ull x, ull y) {
	return (x > y)? x : y;
}

// Function to return the minimum of two signed long long integers
sll smin (sll x, sll y) {
	return (x < y)? x : y;
}

// Function to return the maximum of two signed long long integers
sll smax (sll x, sll y) {
	return (x > y)? x : y;
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
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
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
BEGCMP(phwllcREVcomp){
	DEFLR(hwllc);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwllc structures based on field c
BEGCMP(ptriplecomp){
	DEFLR(hwllc);
	CMPRET(l.c, r.c);
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

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}


// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwll structures based on fields a, b, and c
BEGCMP(phwllABcomp){
	DEFLR(hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}


// Comparison function for hwll

#endif


#endif


#endif

#endif


#endif

#endif

#endif

#endif

#endif

#endif
#endif

#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#e