package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define type aliases for convenience
type ll int64
type ld float64

// Macros for loop iterations and constants
const (
	INF = 1 << 60
	MOD1 = 1000000007
	MOD2 = 998244353
	MAX_N = 1 << 20
	YES = "Yes\n"
	NO = "No\n"
	PN = "\n"
	charsize = 100005 // Maximum character size
	PI = 3.141592653589793238
)

// Function to swap two long long integers
func swap(a, b *ll) {
	c := *b
	*b = *a
	*a = c
}

// Function to read a long long integer
func cin(n *ll) {
	fmt.Scanf("%d", n)
}

// Functions to find maximum and minimum of two or three numbers
func max2(a, b ll) ll {
	if a >= b {
		return a
	}
	return b
}
func min2(a, b ll) ll {
	if a >= b {
		return b
	}
	return a
}
func min3(a, b, c ll) ll {
	if a <= b && a <= c {
		return a
	}
	if b <= c {
		return b
	}
	return c
}
func max3(a, b, c ll) ll {
	if a >= b && a >= c {
		return a
	}
	if b >= c {
		return b
	}
	return c
}

// Functions to find minimum and maximum in an array
func minn(n ll, a []ll) ll {
	b := INF
	for i := 0; i < n; i++ {
		b = min2(b, a[i])
	}
	return b
}
func maxn(n ll, a []ll) ll {
	b := -INF
	for i := 0; i < n; i++ {
		b = max2(b, a[i])
	}
	return b
}

// Functions for power calculations
func POW(a, b ll) ll {
	c := 1
	for i := 0; i < b; i++ {
		c *= a
	}
	return c
}
func POW_d(a, b ld) ld {
	c := 1.0
	for i := 0; i < b; i++ {
		c *= a
	}
	return c
}

// Functions for GCD and LCM calculations
func gcd(a, b ll) ll {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
func lcm(a, b ll) ll {
	return a / gcd(a, b) * b
}

// Functions for modular arithmetic
func mod_MOD1(n ll) ll {
	n += n < 0 && -n/MOD1+1*MOD1 : 0
	return n %= MOD1
}
func mod_p(n, p ll) ll {
	n += n < 0 && -n/p+1*p : 0
	return n %= p
}

// Function to convert a string to a number
func change_into_num(s string, p ll) ll {
	return!p? 0 : POW(10, p-1)*(s[len(s)-p]-'0') + change_into_num(s, p-1)
}

// Function to count the number of digits in a number
func digits(a, b ll) ll {
	return a/b? 1 + digits(a/b, b) : 1
}

// Functions to check if an index is within array bounds
func is_inArr1(x, n ll) ll {
	return x < 0 || x >= n? 0 : 1
}
func is_inArr2(y, x, h, w ll) ll {
	return y < 0 || y >= h || x < 0 || x >= w? 0 : 1
}

// Functions for lower and upper bounds in binary search
func lr_lower(l, r *int, am, val ll, type int) {
	if type < 3 {
		if am < val {
			*l = (*l + *r) / 2
		} else {
			*r = (*l + *r) / 2
		}
	} else {
		if am <= val {
			*l = (*l + *r) / 2
		} else {
			*r = (*l + *r) / 2
		}
	}
}
func lr_upper(l, r *int, am, val ll, type int) {
	if type < 3 {
		if am <= val {
			*l = (*l + *r) / 2
		} else {
			*r = (*l + *r) / 2
		}
	} else {
		if am < val {
			*l = (*l + *r) / 2
		} else {
			*r = (*l + *r) / 2
		}
	}
}

// Comparison functions for lower and upper bounds
func cmp_lower(a, b ll, type int) int {
	if type == 1 {
		if a == b {
			return 1
		}
		return 0
	}
	if type == 2 {
		if a >= b {
			return 1
		}
		return 0
	}
	if a > b {
		return 1
	}
	return 0
}
func cmp_upper(a, b ll, type int) int {
	if type == 1 {
		if a == b {
			return 1
		}
		return 0
	}
	if type == 2 {
		if a <= b {
			return 1
		}
		return 0
	}
	if a < b {
		return 1
	}
	return 0
}

// Function to find the lower bound in an array
func lower_bound(a []ll, l, r ll, val ll, type int) ll {
	for r-l > 1 {
		lr_lower(&l, &r, a[(l+r)/2], val, type)
	}
	return cmp_lower(a[l], val, type)? l : cmp_lower(a[r], val, type)? r : -1
}

// Function to find the upper bound in an array
func upper_bound(a []ll, l, r ll, val ll, type int) ll {
	for r-l > 1 {
		lr_upper(&l, &r, a[(l+r)/2], val, type)
	}
	return cmp_upper(a[r], val, type)? r : cmp_upper(a[l], val, type)? l : -1
}

// Function to count occurrences of a value in an array
func count(a []ll, l, r ll, x ll) ll {
	p := lower_bound(a, l, r, x, 1)
	return p == -1? 0 : upper_bound(a, p, r, x, 1) - p + 1
}

// Global variables for factorization
var factors [2][]ll
var fac_cnt int
var is_factor_prepared int

// Function to prepare factors for prime factorization
func factor_pre() ll {
	for i := 0; i < 1; i++ {
		if is_factor_prepared++ {
			return 0
		}
	}
	tmp := (1e6)/2 + 1
	fac_tmp := make([]ll, tmp)
	for i := 0; i < tmp; i++ {
		fac_tmp[i] = i? 2*i + 1 : 2
	}
	for i := 1; i < tmp; i++ {
		if fac_tmp[i] {
			for j := 3; j*2*i+1 < tmp; j += 2 {
				fac_tmp[(j*2*i+1-1)/2] = 0
			}
		} else {
			continue
		}
	}
	for i := 0; i < tmp; i++ {
		if fac_tmp[i] {
			for j := 0; j < 2; j++ {
				factors[j] = append(factors[j], j? 0 : fac_tmp[i])
			}
		}
	}
	return 0
}

// Function to factor a number and update factor counts
func factor(n, new_common_plus ll) ll {
	factor_pre()
	for i := 0; i < fac_cnt; i++ {
		cnt := 0
		for j := 0; j < 1; j++ {
			for ; cnt += n%factors[0][i] == 0; n /= factors[0][i] {
			}
		}
		factors[1][i] = new_common_plus == 1? cnt : new_common_plus == 2? max2(factors[1][i], cnt) : factors[1][i] + cnt
		if factors[0][i] > n {
			break
		}
	}
	return n
}

// Function to judge if a number is prime
func judge_prime(n ll) ll {
	factor_pre()
	for i := 0; i < fac_cnt; i++ {
		if n < factors[0][i]*factors[0][i] || n == factors[0][i] {
			break
		} else if n%factors[0][i] == 0 {
			n /= n
		}
	}
	return n == 1? 0 : 1
}

// Global variables for modular inverses and factorials
var mf_arr []ll
var inv_arr []ll
var finv_arr []ll
var is_minv_made int
var is_mf_made int
var num_of_inv int = 2*1e6 + 10

// Function to create modular inverses
func makeinv(n, mod ll) ll {
	for i := 0; i < 1; i++ {
		if is_minv_made++ {
			return 0
		}
	}
	inv_arr = make([]ll, 2)
	finv_arr = make([]ll, 2)
	inv_arr[1] = 1
	finv_arr[0] = finv_arr[1] = 1
	for i := 2; i < n+1; i++ {
		inv_arr = append(inv_arr, mod-inv_arr[mod%i]*(mod/i)%mod)
		finv_arr = append(finv_arr, finv_arr[i-1]*inv_arr[i]%mod)
	}
	return 0
}

// Function to create factorials
func make_mf(n, mod ll) ll {
	for i := 0; i < 1; i++ {
		if is_mf_made++ {
			return 0
		}
	}
	mf_arr = make([]ll, 2)
	x := 1
	mf_arr[0] = mf_arr[1] = x
	for i := 2; i < n+1; i++ {
		x = x*i % mod
		mf_arr = append(mf_arr, x)
	}
	return 0
}

// Function to get modular inverse based on whether it's factorial or not
func m_inv(x, mod ll, is_fac ll) ll {
	makeinv(num_of_inv, mod)
	return is_fac? finv_arr[x] : inv_arr[x]
}

// Function to get factorial modulo
func m_f(x, mod ll) ll {
	make_mf(num_of_inv, mod)
	return mf_arr[x]
}

// Function to calculate n choose k modulo
func mod_nck(n, k, mod ll) ll {
	return m_f(n, mod)*m_inv(k, mod, 1)%mod*m_inv(n-k, mod, 1)%mod
}

// Function for modular exponentiation
func m_p(r, n, mod ll) ll {
	t := 1
	s := r
	for n > 0 {
		t = (n & 1)? t*s%mod : t
		s = s*s%mod
		n >>= 1
	}
	return r? t : 0
}

// Functions for modular multiplication
func m_mul2(a, b, mod ll) ll {
	return a * b % mod
}
func m_mul3(a, b, c, mod ll) ll {
	return m_mul2(a*b%mod, c, mod)
}
func m_mul4(a, b, c, d, mod ll) ll {
	return m_mul3(a*b%mod, c, d, mod)
}
func m_mul5(a, b, c, d, e, mod ll) ll {
	return m_mul4(a*b%mod, c, d, e, mod)
}

// Comparison functions for sorting
func upll(a, b *ll) int {
	return *a < *b? -1 : *a > *b? 1 : 0
}
func downll(a, b *ll) int {
	return *a < *b? 1 : *a > *b? -1 : 0
}
func cmp_string(a, b *string) int {
	return strings.Compare(*a, *b)
}
func cmp_char(a, b *byte) int {
	return int(*a) - int(*b)
}

// Sorting functions
func sortup(a []ll, n int) {
	sort.Slice(a[:n], func(i, j int) bool { return a[i] < a[j] })
}
func sortdown(a []ll, n int) {
	sort.Slice(a[:n], func(i, j int) bool { return a[i] > a[j] })
}
func sort_string(n int, size int, s []string) {
	sort.Slice(s[:n], func(i, j int) bool { return strings.Compare(s[i], s[j]) < 0 })
}
func sort_char(s *byte) {
	sort.Slice((*string)(unsafe.Pointer(s)), func(i, j int) bool { return int(s[i]) < int(s[j]) })
}

// Functions to count unique strings and numbers
func unique_string(n int, size int, s []string) int {
	ans := 1
	for i := 1; i < n; i++ {
		if strings.Compare(s[i], s[i-1]) {
			ans++
		}
	}
	return ans
}
func unique_num(n int, a []ll) int {
	ans := 1
	for i := 1; i < n; i++ {
		if a[i]!= a[i-1] {
			ans++
		}
	}
	return ans
}

// Structure for sorting pairs
type fr struct {
	a ll
	b ll
}

// Comparison functions for sorting pairs
func cmp1(p, q *fr) int {
	return p.a - q.a
}
func cmp2(p, q *fr) int {
	return q.a - p.a
}

// Sorting functions for pairs
func strsortup(a []fr, n int) {
	sort.Slice(a[:n], func(i, j int) bool { return a[i].a < a[j].a })
}
func strsortdown(a []fr, n int) {
	sort.Slice(a[:n], func(i, j int) bool { return a[i].a > a[j].a })
}

// Main function
func main() {
	// Read input values for l, r, and d
	var l