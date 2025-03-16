package main

import (
	"fmt"
	"math"
)

const MAX = 707106

var tbl [MAX+1]bool
var sz int
var prime [57100]int
var sqp [147]int

func sieve() {
	i, j, k := 1, 1, 1

	for ; i < 147; i++ {
		k = prime[i]
		for ; j < MAX; j += k {
			tbl[j] = true
		}
	}

	for ; sz = 146; i <= MAX; i += 2 {
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
	l, r, m := 0, sz, 0

	for l < r {
		m = (l + r) >> 1
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
	var A, B, a, b, j, ll, rr int64
	var ans int

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

	sz = bsch(int(math.Sqrt(float64(b >> 1))))

	for i := 0; i <= sz; i++ {
		p := prime[i]
		for k, j := 1, int64(p); j <= b; j *= int64(p) {
			pp[k] = j
			k++
		}
		for k--; k > 0; k-- {
			j = pp[k]
			ll = j * (1 + (a - 1) / j)
			rr = j * (b / j)
			for ; ll <= rr; ll += j {
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
			}
		}
	}

	for i := int(b - a + 1); i > 0; i-- {
		if idx[i] > 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

