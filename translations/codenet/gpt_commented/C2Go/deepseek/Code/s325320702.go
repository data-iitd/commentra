package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

// Define type aliases for convenience
type ll = int64
type ld = float64

// Macros for loop iterations and constants
const (
	rep = iota
	repp
	rrep
	INF = 1 << 60
	MOD1 = 1000000007
	MOD2 = 998244353
	MAX_N = 1 << 20
	YES = "Yes"
	NO = "No"
	PN = "\n"
	charsize = 100005 // Maximum character size
	PI = 3.141592653589793238
)

// Function to swap two long long integers
func swap(a, b *ll) {
	*a, *b = *b, *a
}

// Function to read a long long integer
func cin(n *ll) {
	fmt.Scan(n)
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
func minn(n int, a []ll) ll {
	b := INF
	for i := 0; i < n; i++ {
		if a[i] < b {
			b = a[i]
		}
	}
	return b
}
func maxn(n int, a []ll) ll {
	b := -INF
	for i := 0; i < n; i++ {
		if a[i] > b {
			b = a[i]
		}
	}
	return b
}

// Functions for power calculations
func POW(a, b ll) ll {
	c := int64(1)
	for i := 0; i < b; i++ {
		c *= a
	}
	return c
}
func POW_d(a, b ld) ld {
	c := float64(1)
	for i := 0; i < int(b); i++ {
		c *= a
	}
	return c
}

// Functions for GCD and LCM calculations
func gcd(a, b ll) ll {
	if b == 0 {
		return a
	}
	return gcd(b, a % b)
}
func lcm(a, b ll) ll {
	return a / gcd(a, b) * b
}

// Functions for modular arithmetic
func mod_MOD1(n ll) ll {
	if n < 0 {
		n += (-n)/MOD1 + 1
	}
	return n % MOD1
}
func mod_p(n ll, p ll) ll {
	if n < 0 {
		n += (-n)/p + 1
	}
	return n % p
}

// Function to convert a string to a number
func change_into_num(s string, len int, p int) ll {
	if p == 0 {
		return 0
	}
	return POW(10, p-1) * ll(s[len-p]-'0') + change_into_num(s, len, p-1)
}

// Function to count the number of digits in a number
func digits(a ll, b ll) ll {
	if a < b {
		return 1
	}
	return 1 + digits(a/b, b)
}

// Functions to check if an index is within array bounds
func is_inArr1(x, n int) bool {
	return x < 0 || x >= n
}
func is_inArr2(y, x, h, w int) bool {
	return y < 0 || y >= h || x < 0 || x >= w
}

// Functions for lower and upper bounds in binary search
func lr_lower(l, r *int, am, val int, type int) {
	if am < val {
		*l = (*l + *r) / 2
	} else {
		*r = (*l + *r) / 2
	}
}
func lr_upper(l, r *int, am, val int, type int) {
	if am <= val {
		*l = (*l + *r) / 2
	} else {
		*r = (*l + *r) / 2
	}
}

// Comparison functions for lower and upper bounds
func cmp_lower(a, b, type int) bool {
	if type == 1 {
		return a == b
	}
	if type == 2 {
		return a >= b
	}
	return a > b
}
func cmp_upper(a, b, type int) bool {
	if type == 1 {
		return a == b
	}
	if type == 2 {
		return a <= b
	}
	return a < b
}

// Function to find the lower bound in an array
func lower_bound(a []ll, l, r, val int, type int) int {
	for r-l > 1 {
		lr_lower(&l, &r, a[(l+r)/2], val, type)
	}
	if cmp_lower(a[l], val, type) {
		return l
	}
	if cmp_lower(a[r], val, type) {
		return r
	}
	return -1
}

// Function to find the upper bound in an array
func upper_bound(a []ll, l, r, val int, type int) int {
	for r-l > 1 {
		lr_upper(&l, &r, a[(l+r)/2], val, type)
	}
	if cmp_upper(a[r], val, type) {
		return r
	}
	if cmp_upper(a[l], val, type) {
		return l
	}
	return -1
}

// Function to count occurrences of a value in an array
func count(a []ll, l, r, x int) int {
	p := lower_bound(a, l, r, x, 1)
	if p == -1 {
		return 0
	}
	return upper_bound(a, p, r, x, 1) - p + 1
}

// Global variables for factorization
var factors [2][]ll
var fac_cnt int
var is_factor_prepared int

// Function to prepare factors for prime factorization
func factor_pre() {
	if is_factor_prepared > 0 {
		return
	}
	is_factor_prepared++
	tmp := (1e6)/2 + 1
	fac_tmp := make([]ll, tmp)
	for i := 0; i < tmp; i++ {
		fac_tmp[i] = i*2 + 1
	}
	for i := 1; i < tmp; i++ {
		if fac_tmp[i] != 0 {
			for j := 3; j <= tmp/(2*i+1); j += 2 {
				if j*(2*i+1) < tmp {
					fac_tmp[(j*(2*i+1)-1)/2] = 0
				}
			}
		}
	}
	for i := 0; i < tmp; i++ {
		if fac_tmp[i] != 0 {
			factors[0] = append(factors[0], 2)
			factors[1] = append(factors[1], 0)
			factors[0] = append(factors[0], fac_tmp[i])
			factors[1] = append(factors[1], 0)
		}
	}
}

// Function to factor a number and update factor counts
func factor(n ll, new_common_plus int) ll {
	factor_pre()
	for i := 0; i < len(factors[0]); i++ {
		cnt := 0
		for j := 0; j < 1; j++ {
			for n%factors[0][i] == 0 {
				cnt++
				n /= factors[0][i]
			}
		}
		if new_common_plus == 1 {
			factors[1][i] = cnt
		} else if new_common_plus == 2 {
			factors[1][i] = max2(factors[1][i], cnt)
		} else {
			factors[1][i] += cnt
		}
		if factors[0][i]*factors[0][i] > n {
			break
		}
	}
	return n
}

// Function to judge if a number is prime
func judge_prime(n ll) bool {
	factor_pre()
	for i := 0; i < len(factors[0]); i++ {
		if n < factors[0][i]*factors[0][i] || n == factors[0][i] {
			break
		} else if n%factors[0][i] == 0 {
			n /= n
		}
	}
	return n == 1
}

// Global variables for modular inverses and factorials
var mf_arr []ll
var inv_arr []ll
var finv_arr []ll
var is_minv_made int
var is_mf_made int
const num_of_inv = 2 * 1e6 + 10

// Function to create modular inverses
func makeinv(n ll, mod ll) {
	if is_minv_made > 0 {
		return
	}
	is_minv_made++
	inv_arr = append(inv_arr, 1)
	finv_arr = append(finv_arr, 1)
	for i := 2; i <= n; i++ {
		inv_arr = append(inv_arr, mod-inv_arr[mod%i]*(mod/i)%mod)
		finv_arr = append(finv_arr, finv_arr[i-1]*inv_arr[i]%mod)
	}
}

// Function to create factorials
func make_mf(n ll, mod ll) {
	if is_mf_made > 0 {
		return
	}
	is_mf_made++
	x := int64(1)
	mf_arr = append(mf_arr, x)
	for i := 2; i <= n; i++ {
		x = x * int64(i) % mod
		mf_arr = append(mf_arr, x)
	}
}

// Function to get modular inverse based on whether it's factorial or not
func m_inv(x ll, mod ll, is_fac int) ll {
	makeinv(num_of_inv, mod)
	if is_fac == 1 {
		return finv_arr[x]
	}
	return inv_arr[x]
}

// Function to get factorial modulo
func m_f(x ll, mod ll) ll {
	make_mf(num_of_inv, mod)
	return mf_arr[x]
}

// Function to calculate n choose k modulo
func mod_nck(n, k, mod ll) ll {
	return m_f(n, mod) * m_inv(k, mod, 1) % mod * m_inv(n-k, mod, 1) % mod
}

// Function for modular exponentiation
func m_p(r ll, n ll, mod ll) ll {
	t := int64(1)
	s := r
	for n > 0 {
		if n&1 == 1 {
			t = t * s % mod
		}
		s = s * s % mod
		n >>= 1
	}
	return r
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
func upll(a, b interface{}) int {
	return a.(int64) < b.(int64) ? -1 : a.(int64) > b.(int64) ? 1 : 0
}
func downll(a, b interface{}) int {
	return a.(int64) < b.(int64) ? 1 : a.(int64) > b.(int64) ? -1 : 0
}
func cmp_string(a, b interface{}) int {
	return strings.Compare(a.(string), b.(string))
}
func cmp_char(a, b interface{}) int {
	return int(a.(byte) - b.(byte))
}

// Sorting functions
func sortup(a []ll, n int) {
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
}
func sortdown(a []ll, n int) {
	sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })
}
func sort_string(n int, size int, s []string) {
	sort.Slice(s, func(i, j int) bool { return strings.Compare(s[i], s[j]) < 0 })
}
func sort_char(s []byte) {
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
}

// Functions to count unique strings and numbers
func unique_string(n int, size int, s []string) int {
	ans := 1
	for i := 1; i < n; i++ {
		if s[i] != s[i-1] {
			ans++
		}
	}
	return ans
}
func unique_num(n int, a []ll) int {
	ans := 1
	for i := 1; i < n; i++ {
		if a[i] != a[i-1] {
			ans++
		}
	}
	return ans
}

// Structure for sorting pairs
type fr struct {
	a, b int64
}

// Comparison functions for sorting pairs
func cmp1(p, q interface{}) int {
	return int(p.(fr).a - q.(fr).a)
}
func cmp2(p, q interface{}) int {
	return int(q.(fr).a - p.(fr).a)
}

// Sorting functions for pairs
func strsortup(a []fr, n int) {
	sort.Slice(a, func(i, j int) bool { return cmp1(a[i], a[j]) < 0 })
}
func strsortdown(a []fr, n int) {
	sort.Slice(a, func(i, j int) bool { return cmp2(a[i], a[j]) < 0 })
}

// Main function
func main() {
	// Read input values for l, r, and d
	var l, r, d int64
	var ans int64
	cin(&l)
	cin(&r)
	cin(&d)

	// Count the multiples of d in the range [l, r]
	for i := l; i <= r; i++ {
		if i%d == 0 {
			ans++
		}
	}

	// Output the result
	fmt.Println(ans)
}

