package main

import (
	"fmt"
	"math"
)

const MAX = 707106 // sqrt(10^12/2)

var tbl [MAX + 1]bool

var sz int // max sz = 57084, prime[0] = 2, prime[57083] = 707099
var prime [57100]int // Declare an array 'prime' of size 57100 to store prime numbers

func sieve() {
	var k int

	// Sieve of Eratosthenes algorithm to find prime numbers up to sqrt(MAX)
	for i := 1; i < 147; i++ {
		k = prime[i] // Get the current prime number
		for j := k * k; j <= MAX; j += k {
			tbl[j] = true // Mark all multiples of 'k' as composite in 'tbl' array
		}
	}
	// Find all prime numbers greater than sqrt(MAX)
	for i := 853; i <= MAX; i += 2 {
		if !tbl[i] {
			prime[sz] = i // If 'i' is not marked as composite, it is a prime number
			sz++
		}
	}
}

var base [1000002]int
var idx [1000002]int
var pp [41]int64 // 2^40 = 1099511627776 >= 10^12

func bsch(x int) int {
	l, r := 0, sz

	// Binary search algorithm to find the index of the largest prime number 'p' such that 'p^2 <= x'
	for l < r {
		m := (l + r) >> 1 // Calculate the middle index 'm'
		if prime[m] == x {
			return m // If 'x' is a prime number, return its index
		}
		if prime[m] < x {
			l = m + 1 // If 'prime[m]' is smaller than 'x', 'l' should be updated
		} else {
			r = m // Otherwise, 'r' should be updated
		}
	}
	return l - 1 // Return the index of the largest prime number 'p' such that 'p^2 <= x'
}

func main() {
	var A, B int64
	var a, b int64

	sieve() // Call the Sieve of Eratosthenes algorithm to find prime numbers

	fmt.Scanf("%d %d", &A, &B) // Read two integers 'A' and 'B' from the standard input
	a = A - B
	b = A + B
	if b <= 1 {
		fmt.Println(0)
		return
	}
	if a <= 1 {
		a = 2
	}

	sz = bsch(int(math.Sqrt(float64(b >> 1)))) // Find the largest prime number 'p' such that 'p^2 <= b' using binary search

	for i := range idx {
		idx[i] = 1 // Initialize all elements of 'idx' array to 1
	}
	for i := range base {
		base[i] = 0 // Initialize all elements of 'base' array to 0
	}

	for i := 0; i <= sz; i++ {
		p := prime[i] // Get the current prime number
		k := 1
		for j := int64(p); j <= b; j *= int64(p) {
			pp[k] = j
			k++
		}
		for k--; k >= 0; k-- {
			j := pp[k]
			ll := j * (1 + (a - 1) / j)
			rr := j * (b / j)
			for ll <= rr {
				x := int(ll - a) // Calculate the index 'x' of the segment
				if idx[x] == 0 || base[x] == p {
					ll += j
					continue
				}
				base[x] = p
				idx[x] = k
				ll += j
			}
		}
	}

	ans := 0
	i = int(b - a + 1) // Initialize 'ans' to 0 and the loop counter 'i' to the number of segments
	for i-- > 0 {
		if idx[i] != 0 {
			ans++
		}
	}
	fmt.Println(ans) // Output the result 'ans' and terminate the program
}

// <END-OF-CODE>
