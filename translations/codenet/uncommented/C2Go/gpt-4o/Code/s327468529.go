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
	a int64
	b int64
}

type hwllc struct {
	a int64
	b int64
	c int64
}

type linell struct {
	a hwll
	b hwll
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
	vra, vrb, vrc float64
	vda, vdb, vdc float64
	ch, dh byte

	cnt   [3]int64
	pcnt  uint64
	x     [3005][3005]uint64
	s     string
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

func solve() int64 {
	var result int64 = 1
	var maybe int64 = 0
	var sum int64 = 0

	for i := 0; i < int(n*3); i++ {
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
			if (cnt[(v+1)%3]+cnt[(v+2)%3]) > cnt[v] {
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
	fmt.Scan(&n, &m)
	fmt.Scan(&s)

	solve()
}

// <END-OF-CODE>
