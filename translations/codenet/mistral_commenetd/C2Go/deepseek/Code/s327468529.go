package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

const (
	BIG        = 2000000007
	VERYBIG    = 20000000000000007
	MOD        = 1000000007
	FOD        = 998244353
	N_MAX      = 1048576
	M_PI       = 3.14159265358979323846264338327950
)

type hwll struct {
	a int64
	b int64
}

type hwllc struct {
	a int64
	b int64
	c int64
}

type hwreal struct {
	a float64
	b float64
}

var (
	n, m int64
	h, w int64
	k    int64
	q    int64
	va, vb, vc, vd, ve, vf int64
	ua, ub, uc, ud, ue, uf uint64
	vra, vrb, vrc           float64
	vda, vdb, vdc           float64
	ch, dh                  byte
)

func umin(x, y uint64) uint64 {
	if x < y {
		return x
	}
	return y
}

func umax(x, y uint64) uint64 {
	if x > y {
		return x
	}
	return y
}

func smin(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

func smax(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func gcd(x, y uint64) uint64 {
	for y != 0 {
		x, y = y, x%y
	}
	return x
}

func bitpow(a, x, modulo uint64) uint64 {
	result := uint64(1)
	for x > 0 {
		if x%2 == 1 {
			result = (result * a) % modulo
		}
		a = (a * a) % modulo
		x /= 2
	}
	return result
}

func divide(a, b, modulo uint64) uint64 {
	return (a * bitpow(b, modulo-2, modulo)) % modulo
}

func udiff(a, b uint64) uint64 {
	if a > b {
		return a - b
	}
	return b - a
}

func bitcount(n uint64) int {
	count := 0
	for n > 0 {
		count += int(n & 1)
		n >>= 1
	}
	return count
}

func main() {
	// Initialize variables
	n = 4
	m = 0

	// Read input values
	// fmt.Scanf("%llu", &m)
	// fmt.Scanf("%llu%llu", &h, &w)
	// fmt.Scanf("%llu", &k, &n, &m)
	// fmt.Scanf("%llu%llu", &h, &w)
	// fmt.Scanf("%llu", &q)
	// fmt.Scanf("%lld%lld", &va, &vb, &vc, &vd)
	// va--
	// vb--
	var s string
	fmt.Scanf("%s", &s)
	// fmt.Scanf("%s", t)
	// fmt.Scanf("%s", u)
	// fmt.Scanf("%llu", &k)
	// fmt.Scanf("%lld", &m)

	// Initialize arrays
	a := make([]int64, N_MAX)
	b := make([]int64, N_MAX)
	c := make([]int64, N_MAX)

	// Read input values
	for i := 0; i < int(n); i++ {
		fmt.Scanf("%lld", &b[i])
	}

	// Read input values
	for i := 0; i < int(m); i++ {
		fmt.Scanf("%lld", &c[i])
	}

	// Read input value
	fmt.Scanf("%llu", &q)

	// Call the solve function
	solve()
}

func solve() int64 {
	var i, j int64
	// Initialize variables
	result := int64(1)
	// ull result = 0
	// double dresult = 0
	// ull maybe = 0
	// ull sum = 0
	// sll maybe = 0
	// sll sum = 0
	// sll item
	// sll *dpcell

	// for (i = 0; i < h; i++) {
	// 	for (j = 0; j < w; j++) {
	// 		x[i][j] = (table[i][j] - 1) / w
	// 	}
	// }

	// result = 1
	for i = 0; i < n*3; i++ {
		var v int64
		switch s[i] {
		case 'R':
			v = 0
		case 'G':
			v = 1
		case 'B':
			v = 2
		}
		// if (cnt[(v + 1) % 3] && cnt[(v + 2) % 3]) {
		// 	result *= (cnt[(v + 1) % 3] * cnt[(v + 2) % 3] % FOD)
		// 	pcnt--;
		// 	result %= FOD;
		// 	cnt[(v + 1) % 3]--;
		// 	cnt[(v + 2) % 3]--;
		// } else {

		// 	if ((cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]) {
		// 		result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v];
		// 		result %= FOD;
		// 		pcnt++;
		// 	}

		// 	cnt[v]++;
		// }
		if cnt[(v+1)%3] > 0 && cnt[(v+2)%3] > 0 {
			result *= pcnt
			pcnt--
			result %= FOD
			cnt[(v+1)%3]--
			cnt[(v+2)%3]--
		} else {

			if cnt[(v+1)%3]+cnt[(v+2)%3] > cnt[v] {
				result *= (cnt[(v+1)%3] + cnt[(v+2)%3]) - cnt[v]
				result %= FOD
				pcnt++
			}

			cnt[v]++
		}
		// fmt.Printf("%llu\n", result)
	}

	for i = 1; i <= n; i++ {
		result = (result * i) % FOD
	}

	fmt.Printf("%lld\n", result)
	// fmt.Printf("%.15f\n", dresult)
	// puts(s)

	return 0

	// success:
	// puts("YES");
	// puts("Yes");
	// fmt.Printf("%llu\n", result);
	// puts("0");
	// puts("First");
	// return 0

	// fail:
	// puts("NO");
	// puts("No");
	// puts("0");
	// puts("-1");
	// puts("-1 -1 -1");
	// puts("Second");
	// return 1
}

