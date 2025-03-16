package main

import (
	"fmt"
	"math"
	"strings"
)

const (
	BIG      = 2000000007
	VERYBIG  = 20000000000000007
	MOD      = 1000000007
	FOD      = 998244353
	N_MAX    = 1048576
)

type hwll struct {
	a, b int64
}

type hwllc struct {
	a, b, c int64
}

type linell struct {
	a, b hwll
}

type hwreal struct {
	a, b float64
}

var (
	n, m int64
	h, w int64
	k, q int64
	va, vb, vc, vd, ve, vf int64
	ua, ub, uc, ud, ue, uf uint64
	vra, vrb, vrc float64
	vda, vdb, vdc float64
	ch, dh byte
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
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

func bitpow(a, x, modulo uint64) uint64 {
	result := uint64(1)
	for x > 0 {
		if x&1 == 1 {
			result = (result * a) % modulo
		}
		x /= 2
		a = (a * a) % modulo
	}
	return result
}

func divide(a, b, modulo uint64) uint64 {
	return (a * bitpow(b, modulo-2, modulo)) % modulo
}

func udiff(a, b uint64) uint64 {
	if a >= b {
		return a - b
	}
	return b - a
}

func sdiff(a, b int64) int64 {
	if a >= b {
		return a - b
	}
	return b - a
}

func bitcount(n uint64) int {
	result := 0
	for n > 0 {
		if n&1 == 1 {
			result++
		}
		n /= 2
	}
	return result
}

func ncr(n, r int64, m uint64) uint64 {
	if n < 0 || r < 0 || n < r {
		return 0
	}
	return frac[n] * (invf[r] * invf[n-r % m) % m
}

var (
	frac  [N_MAX * 3]uint64
	invf  [N_MAX * 3]uint64
	a     [N_MAX + 5]int64
	b     [N_MAX + 5]int64
	c     [N_MAX + 5]int64
	d     [N_MAX + 5]int64
	e     [N_MAX * 4]int64
	s     [N_MAX + 1]byte
	t     [N_MAX + 1]byte
	u     [N_MAX + 1]byte
	xy    [N_MAX + 5]hwll
	tup   [N_MAX + 5]hwllc
	table [3005][3005]int64
	gin   [N_MAX]uint64
	cnt   [3]int64
	pcnt  int64
	x     [3005][3005]uint64
)

func solve() uint64 {
	var result int64 = 1
	var maybe int64 = 0
	var sum int64 = 0
	var item int64
	var dpcell *int64

	for i := int64(0); i < n*3; i++ {
		var v uint64
		switch s[i] {
		case 'R':
			v = 0
		case 'G':
			v = 1
		case 'B':
			v = 2
		}

		if cnt[(v+1)%3] > 0 && cnt[(v+2)%3] > 0 {
			result *= pcnt
			pcnt--
			result %= FOD
			cnt[(v+1)%3]--
			cnt[(v+2)%3]--
		} else {
			if (cnt[(v+1)%3] + cnt[(v+2)%3]) > cnt[v] {
				result *= (cnt[(v+1)%3] + cnt[(v+2)%3]) - cnt[v]
				result %= FOD
				pcnt++
			}
			cnt[v]++
		}
	}

	for i := int64(1); i <= n; i++ {
		result = (result * i) % FOD
	}

	fmt.Println(result)
	return 0
}

func main() {
	fmt.Scanf("%d %d", &n, &m)
	fmt.Scanf("%s", &s)

	solve()
}

// <END-OF-CODE>
