package main

import (
	"fmt"
	"math"
)

const MAX = 707106 // sqrt(10^12/2)

var tbl [MAX + 1]bool

var sz int // max sz = 57084, prime[0] = 2, prime[57083] = 707099
var prime [57100]int // prime[146] = 853, prime[147] = 857

var sqp [147]int // square of prime: sqp[i] = prime[i] * prime[i]

func sieve() {
	for i := 1; i < 147; i++ {
		k := prime[i]
		for j := sqp[i]; j < MAX; j += k {
			tbl[j] = true
		}
	}
	for sz = 146; i := 853; i <= MAX; i += 2 {
		if !tbl[i] {
			prime[sz] = i
			sz++
		}
	}
}

var base [1000002]int
var idx [1000002]int
var pp [41]int64 // 2^40 = 1099511627776 >= 10^12

func bsch(x int) int {
	l, r := 0, sz
	for l < r {
		m := (l + r) >> 1
		if prime[m] == x {
			return m
		}
		if prime[m] < x {
			l = m + 1
		} else {
			r = m
		}
	}
	return l - 1
}

func main() {
	sieve()

	var A, B int64
	fmt.Scanf("%d %d", &A, &B)
	a := A - B
	b := A + B
	if b <= 1 {
		fmt.Println(0)
		return
	}
	if a <= 1 {
		a = 2
	}

	sz = bsch(int(math.Sqrt(float64(b >> 1))))

	for i := range idx {
		idx[i] = 1
	}

	for i := 0; i <= sz; i++ {
		p := prime[i]
		k := 1
		for j := int64(p); j <= b; j *= int64(p) {
			pp[k] = j
			k++
		}
		for k--; k > 0; k-- {
			j := pp[k]
			ll := j * (1 + (a - 1) / j)
			rr := j * (b / j)
			for ll <= rr {
				x := int(ll - a)
				if idx[x] == 0 || base[x] == p {
					continue
				}
				if idx[x] < k {
					idx[x] = 0
				} else {
					base[x] = p
					idx[x] = k
				}
				ll += j
			}
		}
	}

	ans := 0
	i := int(b - a + 1)
	for i > 0 {
		i--
		if idx[i] != 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
