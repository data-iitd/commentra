<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

const MAX = 1000000000000 // 10^12

var tbl [MAX+1]byte
var prime [57100]int

func sieve() {
	var i, j, k int

	// Sieve of Eratosthenes algorithm to find prime numbers up to sqrt(MAX)
	for i = 1; i < 147; i++ {
		k = prime[i]
		for j = int(math.Sqrt(float64(k))) + 1; j < MAX; j += k {
			tbl[j] = 1
		}
	}
	// Find all prime numbers greater than sqrt(MAX)
	for i = 853; i <= MAX; i += 2 {
		if tbl[i] == 0 {
			prime[len(prime)] = i
		}
	}
}

func bsch(x int) int {
	var m, l, r int

	// Binary search algorithm to find the index of the largest prime number 'p' such that 'p^2 <= x'
	l = 0
	r = len(prime)
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
	var i, k, p, ans int
	var A, B, a, b, j, ll, rr int64

	sieve() // Call the Sieve of Eratosthenes algorithm to find prime numbers

	fmt.Scanf("%d%d", &A, &B) // Read two integers 'A' and 'B' from the standard input
	a = A - B
	b = A + B
	if b <= 1 {
		fmt.Println(0)
		return
	}
	if a <= 1 {
		a = 2
	}

	sz := bsch(int(math.Sqrt(float64(b >> 1)))) // Find the largest prime number 'p' such that 'p^2 <= b' using binary search

	idx := make([]int, b+1)
	base := make([]int, b+1)

	for i = 0; i <= sz; i++ {
		p = prime[i] // Get the current prime number
		for k = 1; j = p; j *= p; k++ {
			pp[k] = j
		}
		for k--; k >= 0; k-- {
			j = pp[k]
			ll = j*(1+(a-1)/j)
			rr = j*(b/j)
			for ; ll <= rr; ll += j {
				x := int(ll - a) // Calculate the index 'x' of the segment
				if idx[x] == 0 || base[x] == p {
					continue
				}
				base[x] = p
				idx[x] = k
			}
		}
	}

	ans = 0
	for i = int(b - a + 1); i > 0; i-- {
		if idx[i]!= 0 {
			ans++
		}
	}
	fmt.Println(ans) // Output the result 'ans' and terminate the program
}

