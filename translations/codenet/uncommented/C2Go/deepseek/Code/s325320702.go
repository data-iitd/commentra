package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

type ll int

func swap(a, b *ll) {
	*a, *b = *b, *a
}

func cin(n *ll) {
	fmt.Scan(n)
}

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
	} else if b <= c {
		return b
	}
	return c
}

func max3(a, b, c ll) ll {
	if a >= b && a >= c {
		return a
	} else if b >= c {
		return b
	}
	return c
}

func minn(n ll, a []ll) ll {
	b := math.MaxInt64
	for i := 0; i < int(n); i++ {
		if a[i] < b {
			b = a[i]
		}
	}
	return b
}

func maxn(n ll, a []ll) ll {
	b := math.MinInt64
	for i := 0; i < int(n); i++ {
		if a[i] > b {
			b = a[i]
		}
	}
	return b
}

func POW(a, b ll) ll {
	c := ll(1)
	for i := 0; i < int(b); i++ {
		c *= a
	}
	return c
}

func POW_d(a, b float64) float64 {
	c := float64(1)
	for i := 0; i < int(b); i++ {
		c *= a
	}
	return c
}

func gcd(a, b ll) ll {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b ll) ll {
	return a / gcd(a, b) * b
}

func mod_MOD1(n ll) ll {
	if n < 0 {
		n = (-n)/MOD1 + 1
		n %= MOD1
	}
	return n
}

func mod_p(n ll, p ll) ll {
	if n < 0 {
		n = (-n)/p + 1
		n %= p
	}
	return n
}

func change_into_num(s []rune, len, p int) ll {
	if p == 0 {
		return 0
	}
	return POW(10, p-1)*ll(s[len-p]-'0') + change_into_num(s, len, p-1)
}

func digits(a, b ll) ll {
	if a < b {
		return 1
	}
	return 1 + digits(a/b, b)
}

func base(n, a, i ll) ll {
	if i == 1 {
		return n % a
	}
	return base(n/a, a, i-1)
}

func is_inArr1(x, n ll) ll {
	if x < 0 || x >= n {
		return 0
	}
	return 1
}

func is_inArr2(y, x, h, w ll) ll {
	if y < 0 || y >= h || x < 0 || x >= w {
		return 0
	}
	return 1
}

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

func cmp_lower(a, b ll, type int) ll {
	if type == 1 {
		if a == b {
			return 1
		}
		return 0
	} else if type == 2 {
		if a >= b {
			return 1
		}
		return 0
	} else {
		if a > b {
			return 1
		}
		return 0
	}
}

func cmp_upper(a, b ll, type int) ll {
	if type == 1 {
		if a == b {
			return 1
		}
		return 0
	} else if type == 2 {
		if a <= b {
			return 1
		}
		return 0
	} else {
		if a < b {
			return 1
		}
		return 0
	}
}

func lower_bound(a []ll, l, r, val ll, type int) ll {
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

func upper_bound(a []ll, l, r, val ll, type int) ll {
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

func count(a []ll, l, r, x ll) ll {
	p := lower_bound(a, l, r, x, 1)
	if p == -1 {
		return 0
	}
	return upper_bound(a, p, r, x, 1) - p + 1
}

var factors [2][]ll
var fac_cnt int
var is_factor_prepared int

func factor_pre() {
	for i := 0; i < 1; i++ {
		if is_factor_prepared++; is_factor_prepared > 0 {
			return
		}
	}
	tmp := (1e6)/2 + 1
	fac_tmp := make([]ll, tmp)
	for i := 0; i < tmp; i++ {
		fac_tmp[i] = i
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
			for j := 0; j < 2; j++ {
				factors[j] = append(factors[j], j)
			}
		}
	}
}

func factor(n ll, new_common_plus int) ll {
	factor_pre()
	for i := 0; i < fac_cnt; i++ {
		cnt := 0
		for j := 0; j < 1; j++ {
			for cnt += int(n % factors[0][i] == 0); n /= factors[0][i] {
			}
		}
		factors[1][i] = new_common_plus
		if factors[0][i] > n {
			break
		}
	}
	return n
}

func judge_prime(n ll) ll {
	factor_pre()
	for i := 0; i < fac_cnt; i++ {
		if n < factors[0][i]*factors[0][i] || n == factors[0][i] {
			break
		} else if n%factors[0][i] == 0 {
			n /= n
		}
	}
	return n == 1 ? 0 : 1
}

var mf_arr, inv_arr, finv_arr []ll
var is_minv_made int
var is_mf_made int
var num_of_inv int = 2*1e6 + 10

func makeinv(n, mod int) {
	for i := 0; i < 1; i++ {
		if is_minv_made++; is_minv_made > 0 {
			return
		}
	}
	inv_arr = append(inv_arr, 1)
	finv_arr = append(finv_arr, 1)
	for i := 2; i <= n; i++ {
		inv_arr = append(inv_arr, mod-inv_arr[mod%i]*(mod/i)%mod)
		finv_arr = append(finv_arr, finv_arr[i-1]*inv_arr[i]%mod)
	}
}

func make_mf(n, mod int) {
	for i := 0; i < 1; i++ {
		if is_mf_made++; is_mf_made > 0 {
			return
		}
	}
	mf_arr = append(mf_arr, 1)
	mf_arr = append(mf_arr, 1)
	for i := 2; i <= n; i++ {
		mf_arr = append(mf_arr, mf_arr[i-1]*i%mod)
	}
}

func m_inv(x, mod int, is_fac int) ll {
	makeinv(num_of_inv, mod)
	if is_fac == 1 {
		return finv_arr[x]
	}
	return inv_arr[x]
}

func m_f(x, mod int) ll {
	make_mf(num_of_inv, mod)
	return mf_arr[x]
}

func mod_nck(n, k, mod int) ll {
	return m_f(n, mod) * m_inv(k, mod, 1) % mod * m_inv(n-k, mod, 1) % mod
}

func m_p(r, n, mod int) ll {
	t := 1
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

func m_mul2(a, b, mod int) ll {
	return a * b % mod
}

func m_mul3(a, b, c, mod int) ll {
	return m_mul2(a*b%mod, c, mod)
}

func m_mul4(a, b, c, d, mod int) ll {
	return m_mul3(a*b%mod, c, d, mod)
}

func m_mul5(a, b, c, d, e, mod int) ll {
	return m_mul4(a*b%mod, c, d, e, mod)
}

func upll(a, b interface{}) int {
	return a.(ll) < b.(ll) ? -1 : a.(ll) > b.(ll) ? 1 : 0
}

func downll(a, b interface{}) int {
	return a.(ll) < b.(ll) ? 1 : a.(ll) > b.(ll) ? -1 : 0
}

func cmp_string(a, b interface{}) int {
	return strings.Compare(a.(string), b.(string))
}

func cmp_char(a, b interface{}) int {
	return int(a.(rune) - b.(rune))
}

func sortup(a []ll) {
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
}

func sortdown(a []ll) {
	sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })
}

func sort_string(n int, size int, s [][]string) {
	sort.Slice(s, func(i, j int) bool { return strings.Compare(s[i][0], s[j][0]) < 0 })
}

func sort_char(s []rune) {
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
}

func unique_string(n int, size int, s [][]string) int {
	ans := 1
	for i := 1; i < n; i++ {
		if strings.Compare(s[i][0], s[i-1][0]) != 0 {
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

type fr struct {
	a, b ll
}

func cmp1(a, b interface{}) int {
	return int(a.(fr).a - b.(fr).a)
}

func cmp2(a, b interface{}) int {
	return int(b.(fr).a - a.(fr).a)
}

func strsortup(a []fr) {
	sort.Slice(a, func(i, j int) bool { return cmp1(a[i], a[j]) < 0 })
}

func strsortdown(a []fr) {
	sort.Slice(a, func(i, j int) bool { return cmp2(a[i], a[j]) < 0 })
}

func main() {
	var l, r, d ll
	var ans int
	cin(&l)
	cin(&r)
	cin(&d)
	for i := l; i <= r; i++ {
		if i%d == 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

