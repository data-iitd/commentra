
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Define constants for large numbers and modular arithmetic
const (
	BIG  = 2000000007
	VERYBIG = 20000000000000007
	MOD  = 1000000007
	FOD  = 998244353
)

// Define types for unsigned and signed long long integers
type ULL uint64
type SLL int64

// Define maximum size for arrays
const N_MAX = 1048576

// Define structures for various data types
type hwll struct {
	SLL a
	SLL b
}

type hwllc struct {
	SLL a
	SLL b
	SLL c
}

type linell struct {
	hwll a
	hwll b
}

type hwreal struct {
	float64 a
	float64 b
}

// Global variables for various parameters
var (
	n, m SLL
	h, w SLL
	k     SLL
	q     SLL
	va, vb, vc, vd, ve, vf SLL
	ua, ub, uc, ud, ue, uf ULL
	vra, vrb, vrc float64
	vda, vdb, vdc float64
	ch, dh byte
)

// Function to return the minimum of two unsigned long long integers
func umin(a, b ULL) ULL {
	if a < b {
		return a
	}
	return b
}

// Function to return the maximum of two unsigned long long integers
func umax(a, b ULL) ULL {
	if a > b {
		return a
	}
	return b
}

// Function to return the minimum of two signed long long integers
func smin(a, b SLL) SLL {
	if a < b {
		return a
	}
	return b
}

// Function to return the maximum of two signed long long integers
func smax(a, b SLL) SLL {
	if a > b {
		return a
	}
	return b
}

// Function to compute the greatest common divisor (GCD) of two unsigned long long integers
func gcd(a, b ULL) ULL {
	for b!= 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}

// Function to compute a^x mod modulo using binary exponentiation
func bitpow(a, x, modulo ULL) ULL {
	result := ULL(1)
	for x > 0 {
		if x&1 == 1 {
			result = (result * a) % modulo
		}
		x >>= 1
		a = (a * a) % modulo
	}
	return result
}

// Function to perform modular division a / b mod modulo
func divide(a, b, modulo ULL) ULL {
	return (a * bitpow(b, modulo-2, modulo)) % modulo
}

// Function to return the absolute difference between two unsigned long long integers
func udiff(a, b ULL) ULL {
	if a >= b {
		return a - b
	}
	return b - a
}

// Function to return the absolute difference between two signed long long integers
func sdiff(a, b SLL) SLL {
	if a >= b {
		return a - b
	}
	return b - a
}

// Function to count the number of set bits in an unsigned long long integer
func bitcount(n ULL) int {
	count := 0
	for n > 0 {
		if n&1 == 1 {
			count++
		}
		n >>= 1
	}
	return count
}

// Macros for comparison functions
//...

// Comparison function for unsigned long long integers
func compareULL(a, b ULL) int32 {
	if a < b {
		return -1
	} else if a > b {
		return 1
	}
	return 0
}

// Comparison function for signed long long integers in reverse order
func compareSLLREV(a, b SLL) int32 {
	if a > b {
		return -1
	} else if a < b {
		return 1
	}
	return 0
}

// Comparison function for signed long long integers
func compareSLL(a, b SLL) int32 {
	if a < b {
		return -1
	} else if a > b {
		return 1
	}
	return 0
}

// Comparison function for characters
func compareChar(a, b byte) int32 {
	if a < b {
		return -1
	} else if a > b {
		return 1
	}
	return 0
}

// Comparison function for double values
func compareDouble(a, b float64) int32 {
	if a < b {
		return -1
	} else if a > b {
		return 1
	}
	return 0
}

// Comparison function for strings
func compareString(a, b string) int32 {
	return bytes.Compare([]byte(a), []byte(b))
}

// Comparison function for hwll structures based on fields a and b
func compareHWLL(a, b hwll) int32 {
	if a.a < b.a {
		return -1
	} else if a.a > b.a {
		return 1
	} else if a.b < b.b {
		return -1
	} else if a.b > b.b {
		return 1
	} else if a.a < b.a {
		return -1
	} else if a.a > b.a {
		return 1
	} else if a.b < b.b {
		return -1
	} else if a.b > b.b {
		return 1
	} else if a.c < b.c {
		return -1
	} else if a.c > b.c {
		return 1
	} else if a.d < b.d {
		return -1
	} else if a.d > b.d {
		return 1
	} else if a.e < b.e {
		return -1
	} else if a.e > b.e {
		return 1
	} else if a.f < b.f {
		return -1
	} else if a.f > b.f {
		return 1
	}

// Comparison function for hwll structures based on fields a and b
func compareHWLL(a, b hwll) int32_t {
	if (a.a < b.a) {
		return -1
	} else if (a.a > b.a) {
		return 1
	} else if (a.b < b.b) {
		return -1
	} else if (a.b > b.b) {
		return 1
	} else if (a.c < b.c) {
		return -1
	} else if (a.c > b.c) {
		return 1
	} else if (a.d < b.d) {
		return -1
	} else if (a.d > b.d) {
		return 1
	} else if (a.e < b.e) {
		return -1
	} else if (a.e > b.e) {
		return 1
	}

// Comparison function for hwll structures based on fields a and b
func compareHWLL(a, b hwll) int32_t {
	if (a.a < b.a) {
		return -1
	} else if (a.a > b.a) {
		return 1
	} else if (a.b < b.b) {
		return -1
	} else if (a.b > b.b) {
		return 1
	} else if (a.c < b.c) {
		return -1
	} else if (a.c > b.c) {
		return 1
	}

// Comparison function for hwll structures based on fields a and b
func compareHWLL(a, b hwll) int32_t {
	if (a.a < b.a) {
		return -1
	} else if (a.a > b.a) {
		return 1
	} else if (a.b < b.b) {
		return -1
	} else if (a.b > b.b) {
		return 1
	} else if (a.c < b.c) {
		return -1
	} else if (a.c > b.c) {
		return 1
	} else if (a.d < b.d) {
		return -1
	} else if (a.d > b.d) {
		return 1
	}

// Function to calculate the factorial of n
ull factorial(ull n) {
	return -1
	} else if (a.e < b.e) {
		return 1
	} else if (a.e > b.e) {
		return 1
	}

// Function to calculate the factorial of n
ull factorial(ull n) {
	return -1
	} else if (a.f < b.f) {
		return 1
	} else if (a.f > b.f) {
		return 1
	}

// Function to calculate the greatest common divisor of n
ull gcd(ull a, b) {
	return -1
	} else if (a.g < b.g) {
		return 1
	} else if (a.h < b.h) {
		return 1
	} else if (a.i < b.i) {
		return -1
	} else if (a.j < b.j) {
		return 1
	} else if (a.k < b.k) {
		return -1
	} else if (a.l < b.l) {
		return 1
	} else if (a.m < b.m) {
		return -1
	} else if (a.n < b.n) {
		return 1
	} else if (a.o < b.o) {
		return -1
	} else if (a.p < b.p) {
		return 1
	} else if (a.q < b.q) {
		return -1
	} else if (a.r < b.r) {
		return 1
	} else if (a.s < b.s) {
		return -1
	} else if (a.t < b.t) {
		return 1
	} else if (a.u < b.u) {
		return -1
	} else if (a.v < b.v) {
		return 1
	} else if (a.w < b.w) {
		return -1
	} else if (a.x < b.x) {
		return 1
	} else if (a.y < b.y) {
		return -1
	} else if (a.z < b.z) {
		return 1
	} else if (a.a < b.a) {
		return -1
	} else if (a.b < b.b) {
		return 1
	} else if (a.c < b.c) {
		return -1
	} else if (a.d < b.d) {
		return 1
	} else if (a.e < b.e) {
		return -1
	} else if (a.f < b.f) {
		return 1
	} else if (a.g < b.g) {
		return -1
	} else if (a.h < b.h) {
		return 1
	} else if (a.i < b.i) {
		return -1
	} else if (a.j < b.j) {
		return 1
	} else if (a.k < b.k) {
		return -1
	} else if (a.l < b.l) {
		return 1
	} else if (a.m < b.m) {
		return -1
	} else if (a.n < b.n) {
		return 1
	} else if (a.o < b.o) {
		return -1
	} else if (a.p < b.p) {
		return 1
	} else if (a.q < b.q) {
		return -1
	} else if (a.r < b.r) {
		return 1
	} else if (a.s < b.s) {
		return -1
	} else if (a.t < b.t) {
		return 1
	} else if (a.u < b.u) {
		return -1
	}

	} else if (a.v < b.v) {
		return 1
	} else if (a.w < b.w) {
		return -1
	} else if (a.x < b.x) {
		return 1
	} else if (a.y < b.y) {
		return -1
	} else if (a.z < b.z) {
		return 1
	} else if (a.a < b.a) {
		return -1
	} else if (a.b < b.b) {
		return 1
	} else if (a.c < b.c) {
		return -1
	} else if (a.d < b.d) {
		return 1
	} else if (a.e < b.e) {
		return -1
	} else if (a.f < b.f) {
		return 1
	} else if (a.g < b.g) {
		return -1
	} else if (a.h < b.h) {
		return 1
	} else if (a.i < b.i) {
		return -1
	} else if (a.j < b.j) {
		return 1
	} else if (a.k < b.k) {
		return -1
	} else if (a.l < b.l) {
		return 1
	} else if (a.m < b.m) {
		return -1
	} else if (a.n < b.n) {
		return 1
	} else if (a.p < b.p) {
		return -1
	} else if (a.q < b.q) {
		return 1
	} else if (a.r < b.r) {
		return -1
	} else if (a.s < b.s) {
		return 1
	} else if (a.t < b.t) {
		return -1
	} else if (a.u < b.u) {
		return 1
	} else if (a.v < b.v) {
		return -1
	} else if (a.h < b.h) {
		return 1
	} else if (a.i < b.i) {
		return -1
	} else if (a.j < b.j) {
		return 1
	} else if (a.k < b.k) {
		return -1
	} else if (a.l < b.l) {
		return 1
	} else if (a.m < b.m) {
		return -1
	} else if (a.n < b.n) {
		return 1
	} else if (a.p < b.p) {
		return -1
	} else if (a.h < b.h) {
		return 1
	} else if (a.i < b.i) {
		return -1
	} else if (a.j < b.j) {
		return 1
	} else if (a.k < b.k) {
		return -1
	} else if (a.l < b.l) {
		return 1
	} else if (a.g < b.g) {
		return -1
	}