package main

import (
	"fmt"
	"math"
)

const MAX = 707106

var tbl [MAX+1]bool

var sz int
var prime = []int{
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
	31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
	73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
	127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
	179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
	233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
	283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
	353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
	419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
	467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
	547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
	607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
	661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
	739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
	811, 821, 823, 827, 829, 839, 853,
}

func sieve() {
	var i, j, k int

	for i = 1; i < 147; i++ {
		k = prime[i]
		for j = prime[i]*prime[i]; j < MAX; j += k {
			tbl[j] = true
		}
	}

	for sz = 146, i = 853; i <= MAX; i += 2 {
		if !tbl[i] {
			prime = append(prime, i)
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

	sz = bsch(int(math.Sqrt(float64(b>>1))))

	for i := range idx {
		idx[i] = 1
	}
	for i := range base {
		base[i] = 0
	}

	for i = 0; i <= sz; i++ {
		p = prime[i]
		for k, j := 1, int64(p); j <= b; j *= int64(p) {
			pp[k] = j
			k++
		}
		for k--; k >= 0; k-- {
			j = pp[k]
			ll = j * (1 + (a-1)/j)
			rr = j * (b / j)
			for ; ll <= rr; ll += j {
				x := int(ll - a)
				if idx[x] == 1 || base[x] == p {
					continue
				}
				base[x] = p
				idx[x] = k
			}
		}
	}

	ans = 0
	for i = int(b - a + 1); i > 0; i-- {
		if idx[i] != 1 {
			ans++
		}
	}
	fmt.Println(ans)
}

