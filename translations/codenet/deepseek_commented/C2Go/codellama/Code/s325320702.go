#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<ctype.h>
type ll int64
type ld float64
const (
	INF = 1 << 60
	MOD1 = 1000000007
	MOD2 = 998244353
	MAX_N = 1 << 20
	YES = "Yes\n"
	NO = "No\n"
	PN = "\n"
	charsize = 100005 //10^5+5
	PI = 3.141592653589793238
)

// Utility Functions
func swap(a, b *ll) {
	c := *b
	*b = *a
	*a = c
}
func cin(n *ll) {
	fmt.Scanf("%d", n)
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
func minn(n ll, a []ll) ll {
	b := INF
	rep(i, 0, n) {
		b = min2(b, a[i])
	}
	return b
}
func maxn(n ll, a []ll) ll {
	b := -INF
	rep(i, 0, n) {
		b = max2(b, a[i])
	}
	return b
}
func POW(a, b ll) ll {
	c := 1
	rep(i, 0, b) {
		c *= a
	}
	return c
}
func POW_d(a, b ld) ld {
	c := 1
	rep(i, 0, b) {
		c *= a
	}
	return c
}
func gcd(a, b ll) ll {
	return b % a
}
func lcm(a, b ll) ll {
	return a / gcd(a, b) * b
}
func mod_MOD1(n ll) ll {
	n += n < 0 ? ((-n) / MOD1 + 1) * MOD1 : 0
	return n % MOD1
}
func mod_p(n, p ll) ll {
	n += n < 0 ? ((-n) / p + 1) * p : 0
	return n % p
}
func change_into_num(s []ll, len, p ll) ll {
	return !p ? 0 : POW(10, p-1)*(s[len-p]-'0') + change_into_num(s, len, p-1)
}
func digits(a, b ll) ll {
	return a/b ? 1 : 1
}
func base(n, a, i ll) ll {
	return i == 1 ? n%a : base(n/a, a, i-1)
}
func is_inArr1(x ll, n ll) ll {
	return x < 0 || x >= n ? 0 : 1
}
func is_inArr2(y, x, h, w ll) ll {
	return y < 0 || y >= h || x < 0 || x >= w ? 0 : 1
}

// Bound and Count Functions
func lr_lower(l, r *ll, am, val ll, type ll) {
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
func lr_upper(l, r *ll, am, val ll, type ll) {
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
func cmp_lower(a, b ll, type ll) ll {
	if type == 1 {
		return a == b ? 1 : 0
	}
	if type == 2 {
		return a >= b ? 1 : 0
	}
	return a > b ? 1 : 0
}
func cmp_upper(a, b ll, type ll) ll {
	if type == 1 {
		return a == b ? 1 : 0
	}
	if type == 2 {
		return a <= b ? 1 : 0
	}
	return a < b ? 1 : 0
}
func lower_bound(a []ll, l, r, val ll, type ll) ll {
	for r-l > 1 {
		lr_lower(&l, &r, a[((l+r)/2)], val, type)
	}
	return cmp_lower(a[l], val, type) ? l : cmp_lower(a[r], val, type) ? r : -1
}
func upper_bound(a []ll, l, r, val ll, type ll) ll {
	for r-l > 1 {
		lr_upper(&l, &r, a[((l+r)/2)], val, type)
	}
	return cmp_upper(a[r], val, type) ? r : cmp_upper(a[l], val, type) ? l : -1
}
func count(a []ll, l, r, x ll) ll {
	p := lower_bound(a, l, r, x, 1)
	return p == -1 ? 0 : upper_bound(a, p, r, x, 1) - p + 1
}

// Factorization and Prime Checking
var factors [2][]ll
var fac_cnt ll
var is_factor_prepared ll
func factor_pre() ll {
	rep(i, 0, 1) {
		if is_factor_prepared++ {
			return 0
		}
	}
	tmp := (1e6) / 2 + 1
	fac_tmp := make([]ll, tmp)
	rep(i, 1, tmp) {
		fac_tmp[i] = i*2 + 1
	}
	rep(i, 1, tmp) {
		if fac_tmp[i] {
			rep(j, 3, tmp/(2*i+1)+1) {
				if j*(2*i+1) < tmp {
					fac_tmp[j*(2*i+1)-1/2] = 0
				}
			}
		} else {
			continue
		}
	}
	rep(i, 0, tmp) {
		if fac_tmp[i] {
			rep(j, 0, 2) {
				factors[j] = append(factors[j], fac_tmp[i])
				fac_cnt++
			}
		}
	}
	return 0
}
func factor(n, new_common_plus ll) ll {
	factor_pre()
	rep(i, 0, fac_cnt) {
		cnt := 0
		rep(j, 0, 1) {
			for cnt += n % factors[0][i] == 0 ? 1 : 0 && (n /= factors[0][i]) % factors[0][i] == 0 {
				continue
			}
		}
		factors[1][i] = new_common_plus == 1 ? cnt : new_common_plus == 2 ? max2(factors[1][i], cnt) : factors[1][i] + cnt
		if factors[0][i] > n {
			break
		}
	}
	return n
}
func judge_prime(n ll) ll {
	factor_pre()
	rep(i, 0, fac_cnt) {
		if n < factors[0][i]*factors[0][i] || n == factors[0][i] {
			break
		} else if n%factors[0][i] == 0 {
			n /= n
		}
	}
	return n == 1 ? 0 : 1
}

// Modular Arithmetic Functions
var mf_arr []ll
var inv_arr []ll
var finv_arr []ll
var is_minv_made ll
var is_mf_made ll
var num_of_inv ll = 2 * 1e6 + 10
func makeinv(n, mod ll) ll {
	rep(i, 0, 1) {
		if is_minv_made++ {
			return 0
		}
	}
	inv_arr = make([]ll, 2)
	finv_arr = make([]ll, 2)
	inv_arr[1] = 1
	finv_arr[0] = finv_arr[1] = 1
	rep(i, 2, n+1) {
		inv_arr = append(inv_arr, i*2+1)
		finv_arr = append(finv_arr, finv_arr[i-1]*inv_arr[i]%mod)
		if n%i == 0 {
			break
		}
	}
	return 0
}
func make_mf(n, mod ll) ll {
	rep(i, 0, 1) {
		if is_mf_made++ {
			return 0
		}
	}
	mf_arr = make([]ll, 2)
	x := 1
	mf_arr[0] = mf_arr[1] = x
	rep(i, 2, n+1) {
		x = x * i % mod
		mf_arr = append(mf_arr, x)
	}
	return 0
}
func m_inv(x, mod, is_fac ll) ll {
	makeinv(num_of_inv, mod)
	return is_fac ? finv_arr[x] : inv_arr[x]
}
func m_f(x ll, mod ll) ll {
	make_mf(num_of_inv, mod)
	return mf_arr[x]
}
func mod_nck(n, k, mod ll) ll {
	return m_f(n, mod)*m_inv(k, mod, 1)%mod*m_inv(n-k, mod, 1)%mod
}
func m_p(r, n, mod ll) ll {
	t := 1
	s := r
	for n > 0 {
		if n&1 != 0 {
			t = t * s % mod
		}
		s = s * s % mod
		n >>= 1
	}
	return r ? t : 0
}
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

// Sorting and String Functions
func upll(a, b unsafe.Pointer) int {
	return *(*ll)(a) < *(*ll)(b) ? -1 : *(*ll)(a) > *(*ll)(b) ? 1 : 0
}
func downll(a, b unsafe.Pointer) int {
	return *(*ll)(a) < *(*ll)(b) ? 1 : *(*ll)(a) > *(*ll)(b) ? -1 : 0
}
func cmp_string(a, b unsafe.Pointer) int {
	return strings.Compare((*string)(a), (*string)(b))
}
func cmp_char(a, b unsafe.Pointer) int {
	return *(*byte)(a) - *(*byte)(b)
}
func sortup(a []ll, n int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}
func sortdown(a []ll, n int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] > a[j]
	})
}
func sort_string(n, size int, s []string) {
	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})
}
func sort_char(s string) {
	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})
}
func unique_string(n int, size int, s []string) int {
	ans := 1
	rep(i, 1, n) {
		if s[i] != s[i-1] {
			ans++
		}
	}
	return ans
}
func unique_num(n int, a []ll) int {
	ans := 1
	rep(i, 1, n) {
		if a[i] != a[i-1] {
			ans++
		}
	}
	return ans
}

type fr struct {
	a ll
	b ll
}

func cmp1(p, q unsafe.Pointer) int {
	return (*fr)(p).a - (*fr)(q).a
}
func cmp2(p, q unsafe.Pointer) int {
	return (*fr)(q).a - (*fr)(p).a
}
func strsortup(a []fr, n int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i].a < a[j].a
	})
}
func strsortdown(a []fr, n int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i].a > a[j].a
	})
}

// Main Function
func main() {
	var l, r, d ll
	var ans ll
	cin(&l)
	cin(&r)
	cin(&d)
	rep(i, l, r+1) {
		if i%d == 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

