// AOJ 2275: Fox Number
// 2017.12.11 bal4u@uu

<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

<<<<<<< HEAD
const MAX = 1000000000000 // 10^12/2
=======
const MAX = 1000000000000 // 10^12
>>>>>>> 98c87cb78a (data updated)

var tbl [MAX+1]byte
var prime [57100]int
var sqp [147]int

func sieve() {
	var i, j, k int
	for i = 1; i < 147; i++ {
		k = prime[i]
		for j = sqp[i]; j < MAX; j += k {
			tbl[j] = 1
		}
	}
	for i = 853; i <= MAX; i += 2 {
		if tbl[i] == 0 {
			prime[i/2] = i
			sqp[i/2] = i * i
		}
	}
}

func bsch(x int) int {
	var m, l, r int
	l = 0
	r = len(prime)
	for l < r {
		m = (l + r) / 2
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

	fmt.Scanf("%d%d", &A, &B)
	a = A - B
	b = A + B
	if b <= 1 {
		fmt.Println(0)
		return
	}
	if a <= 1 {
		a = 2
	}

	sz := bsch(int(math.Sqrt(float64(b >> 1))))

	idx := make([]int, b-a+1)
	for i = 0; i <= sz; i++ {
		p = prime[i]
<<<<<<< HEAD
		for k = 1; k < len(idx); k *= p {
=======
		for k = 1; k <= len(idx); k *= p {
>>>>>>> 98c87cb78a (data updated)
			pp := p * k
			if pp > b {
				break
			}
			idx[pp-a] = k
		}
		for k--; k >= 0; k-- {
<<<<<<< HEAD
			j = p * (k + 1)
=======
			j = p * k
>>>>>>> 98c87cb78a (data updated)
			ll = j * (1 + (a-1)/j)
			rr = j * (b/j)
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

	ans = 0
	for i = 0; i < len(idx); i++ {
		if idx[i] > 0 {
			ans++
		}
	}
	fmt.Println(ans)
}

