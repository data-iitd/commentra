#if 0
cat <<EOF >mistaken-paste
#endif
// thx Ebi-chan!

// Suppress warnings for incompatible pointer types
// #pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

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
const ull BIG = 2000000007;
const ull VERYBIG = 20000000000000007LL;
const ull MOD = 1000000007;
const ull FOD   = 998244353;

// Define types for unsigned and signed long long integers
type Ull uint64
type Sll int64

// Define maximum size for arrays
const N_MAX = 1048576

// Include C++ standard library headers if compiling as C++
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
type Hwll struct {
	sll a;
	sll b;
}

type Hwllc struct {
	sll a;
	sll b;
	sll c;
}

type Linell struct {
	Hwll a;
	Hwll b;
}

type Hwreal struct {
	double a;
	double b;
}

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
func Umin (x, y Ull) Ull {
	if x < y {
		return x;
	} else {
		return y;
	}
}

// Function to return the maximum of two unsigned long long integers
func Umax (x, y Ull) Ull {
	if x > y {
		return x;
	} else {
		return y;
	}
}

// Function to return the minimum of two signed long long integers
func Smin (x, y Sll) Sll {
	if x < y {
		return x;
	} else {
		return y;
	}
}

// Function to return the maximum of two signed long long integers
func Smax (x, y Sll) Sll {
	if x > y {
		return x;
	} else {
		return y;
	}
}

// Function to compute the greatest common divisor (GCD) of two unsigned long long integers
func Gcd (x, y Ull) Ull {
	if y == 0 {
		return x;
	} else {
		return Gcd(y, x % y);
	}
}

// Function to compute a^x mod modulo using binary exponentiation
func Bitpow (a, x, modulo Ull) Ull {
	var result Ull = 1;
	for ; x; x /= 2 {
		if x & 1 {
			result *= a;
			result %= modulo;
		}
		a = (a * a) % modulo;
	}
	return result;
}

// Function to perform modular division a / b mod modulo
func Divide (a, b, modulo Ull) Ull {
	return (a * Bitpow(b, modulo - 2, modulo)) % modulo;
}

// Function to return the absolute difference between two unsigned long long integers
func Udiff (a, b Ull) Ull {
	if a >= b {
		return a - b;
	} else {
		return b - a;
	}
}

// Function to return the absolute difference between two signed long long integers
func Sdiff (a, b Sll) Sll {
	if a >= b {
		return a - b;
	} else {
		return b - a;
	}
}

// Function to count the number of set bits in an unsigned long long integer
func Bitcount (n Ull) int {
	var result int = 0;
	for ; n; n /= 2 {
		if n & 1 {
			result++;
		}
	}
	return result;
}

// Macros for comparison functions
#define BEGCMP(NAME) func NAME (left, right interface{}) int
#define DEFLR(TYPE) var l TYPE = left.(TYPE); var r TYPE = right.(TYPE)
#define CMPRET(L, R) if L < R { return -1 }; if L > R { return +1 }

// Comparison function for unsigned long long integers
func Pullcomp (left, right interface{}) int {
	DEFLR(Ull);
	CMPRET(l, r);
	return 0;
}

// Comparison function for signed long long integers in reverse order
func Prevcomp (left, right interface{}) int {
	DEFLR(Sll);
	CMPRET(r, l);
	return 0;
}

// Comparison function for signed long long integers
func Psllcomp (left, right interface{}) int {
	DEFLR(Sll);
	CMPRET(l, r);
	return 0;
}

// Comparison function for characters
func Pcharcomp (left, right interface{}) int {
	DEFLR(byte);
	CMPRET(l, r);
	return 0;
}

// Comparison function for double values
func Pdoublecomp (left, right interface{}) int {
	DEFLR(float64);
	CMPRET(l, r);
	return 0;
}

// Comparison function for strings
func Pstrcomp (left, right interface{}) int {
	var l string = left.(string);
	var r string = right.(string);

	return strings.Compare(l, r);
}

// Comparison function for hwll structures based on fields a and b
func PhwllABcomp (left, right interface{}) int {
	DEFLR(Hwll);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}

// Comparison function for hwll structures in reverse order
func PhwllREVcomp (left, right interface{}) int {
	DEFLR(Hwll);
	CMPRET(l.b, r.b);
	CMPRET(l.a, r.a);
	return 0;
}

// Comparison function for hwllc structures based on fields a, b, and c
func Ptriplecomp (left, right interface{}) int {
	DEFLR(Hwllc);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwllc structures in reverse order
func PtripleREVcomp (left, right interface{}) int {
	DEFLR(Hwllc);
	CMPRET(l.b, r.b);
	CMPRET(l.a, r.a);
	CMPRET(l.c, r.c);
	return 0;
}

// Comparison function for hwllc structures based on field c, then a, then b
func PtripleCABcomp (left, right interface{}) int {
	DEFLR(Hwllc);
	CMPRET(l.c, r.c);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}

// Comparison function for hwreal structures based on fields a and b
func Phwrealcomp (left, right interface{}) int {
	DEFLR(Hwreal);
	CMPRET(l.a, r.a);
	CMPRET(l.b, r.b);
	return 0;
}

// Comparison function for linell structures based on their components
func Pquadcomp (left, right interface{}) int {
	var l Linell = left.(Linell);
	var r Linell = right.(Linell);

	var ac int = PhwllABcomp(&(l.a), &(r.a));
	if ac!= 0 {
		return ac;
	}
	var bc int = PhwllABcomp(&(l.b), &(r.b));
	if bc!= 0 {
		return bc;
	}

	return 0;
}

// Comparison function for hwllc structures based on a fraction
func Pfracomp (left, right interface{}) int {
	var l Hwllc = left.(Hwllc);
	var r Hwllc = right.(Hwllc);

	CMPRET(l.a * r.b, l.b * r.a);
	return 0;
}

// Function to check if a value x is within a range [left, right]
func Isinrange (left, x, right Sll) bool {
	return left <= x && x <= right;
}

// Function to check if a value x is within a range [left, right] or vice versa
func Isinrange_soft (left, x, right Sll) bool {
	return left <= x && x <= right || left >= x && x >= right;
}

// Function to swap two signed long long integers
func Sw (l, r *Sll) {
	if *l == *r {
		return;
	}
	var t Sll = *l;
	*l = *r;
	*r = t;
}

// Arrays for factorials and their inverses
var frac [N_MAX * 3] Ull;
var invf [N_MAX * 3] Ull;

// Function to compute n choose r modulo m
func Ncr (n, r Sll, m Ull) Ull {
	if n < 0 || r < 0 || n < r {
		return 0;
	}
	return frac[n] * (invf[r] * invf[n - r] % m) % m;
}

// Arrays for various data types
var a [N_MAX + 5] Sll;
var b [N_MAX + 5] Sll;
var c [N_MAX + 5] Sll;
var d [N_MAX + 5] Sll;
var e [N_MAX * 4] Sll;
var s [N_MAX + 1] byte;
var t [N_MAX + 1] byte;
var u [N_MAX + 1] byte;
var xy [N_MAX + 5] Hwll;
var tup [N_MAX + 5] Hwllc;
var table [3005][3005] Sll;
var gin [N_MAX] Ull;

// Initialize counters and arrays for computations
var cnt [3] Sll;
var pcnt Ull;
var x [3005][3005] Ull;

// Main solving function
func Solve () Ull {
	var i, j, ki, li Sll;
	var result Ull = 1; // Variable to store the result
	var maybe Ull = 0; // Variable for potential calculations
	var sum Sll = 0; // Variable for summation
	var item Sll; // Temporary variable
	var dpcell *Sll; // Pointer for dynamic cell references

	// Initialize result
	result = 1;

	// Process the input string and calculate the result based on color counts
	for i = 0; i < n * 3; i++ {
		var v Ull;
		switch s[i] {
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
		if cnt[(v + 1) % 3] && cnt[(v + 2) % 3] {
			result *= pcnt; // Multiply by the count of available combinations
			pcnt--; // Decrease the count of available combinations
			result %= FOD; // Apply modulo
			cnt[(v + 1) % 3]--; // Decrease count of the first color
			cnt[(v + 2) % 3]--; // Decrease count of the second color
		} else {
			// If there are more of the other two colors than the current color
			if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v] {
				result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
				result %= FOD; // Apply modulo
				pcnt++; // Increase the count of available combinations
			}
			cnt[v]++; // Increase count of the current color
		}
	}

	// Calculate the factorial of n for final result
	for i = 1; i <= n; i++ {
		result = (result * i) % FOD;
	}

	// Output the result
	fmt.Printf("%d\n", result);
	return 0;

	success:
	fmt.Println("Yes"); // Indicate success
	return 0;

	fail:
	fmt.Println("-1"); // Indicate failure
	return 1;
}

// Main function to execute the program
func main () {
	var i, j int;

	n = 4; // Set initial value for n
	m = 0; // Set initial value for m

	// Read input values
	fmt.Scanf("%d", &n, &m);
	fmt.Scanf("%s", s); // Read the string input

	// Call the solve function to compute the result
	Solve();

	return; // Exit the program
}


Translate the above Go code to Python and end with comment "