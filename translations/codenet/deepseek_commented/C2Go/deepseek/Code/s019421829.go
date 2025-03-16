package main

import (
	"fmt"
	"math"
)

const MAX = 707106
const MAX_PRIMES = 57100

var tbl [MAX + 1]bool
var prime [MAX_PRIMES]int
var sqp [147]int

func sieve() {
	var i, j, k int

	for i = 1; i < 147; i++ {
		k = prime[i]
		for j = sqp[i]; j < MAX; j += k {
			tbl[j] = true
		}
	}
	for sz := 146; i <= MAX; i += 2 {
		if !tbl[i] {
			prime[sz] = i
			sz++
		}
	}
}

var base [1000002]int
var idx [1000002]int
var pp [41]int64

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
	var i, k, p, ans int
	var A, B, a, b, j, ll, rr int64

	sieve()

	fmt.Scan(&A, &B)
	a = A - B
	b = A + B
	if b <= 1 {
		fmt.Println("0")
		return
	}
	if a <= 1 {
		a = 2
	}

	sz = bsch(int(math.Sqrt(float64(b>>1)))) + 1

	for i := 0; i <= sz; i++ {
		p = prime[i]
		for k, j := 1, int64(p); j <= b; j *= int64(p) {
			pp[k] = j
			k++
		}
		for kk := k - 1; kk > 0; kk-- {
			j := pp[kk]
			ll = j * (1 + (a - 1) / j)
			rr = j * (b / j)
			for ; ll <= rr; ll += j {
				x := int(ll - a)
				if idx[x] == 0 || base[x] == p {
					continue
				}
				if idx[x] < kk {
					idx[x] = 0
				} else {
					base[x] = p
					idx[x] = kk
				}
			}
		}
	}

	ans = 0
	for i := 0; i < int(b-a+1); i++ {
		if idx[i] != 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

