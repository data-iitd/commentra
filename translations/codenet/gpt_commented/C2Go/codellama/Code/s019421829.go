
package main

import (
	"fmt"
	"math"
)

const (
	MAX   = 707106			// Define the maximum value for the sieve (sqrt(10^12/2))
	MAXP  = 57100			// Define the maximum number of prime numbers
	MAXSQ = 147				// Define the maximum number of prime square values
)

var (
	tbl [MAX+1]byte			// Array to mark non-prime numbers
	prime [MAXP]int			// Predefined array of prime numbers
	sqp [MAXSQ]int			// Array to hold squares of the first 146 prime numbers
	pp [41]int64			// Array to hold powers of 2 up to 2^40
	base [1000002]int		// Arrays to hold base values and indices for calculations
	idx [1000002]int
	sz int					// Variable to hold the size of the prime array
)

// Function to generate prime numbers using the Sieve of Eratosthenes
func sieve() {
	var i, j, k int

	// Mark non-prime numbers in the tbl array
	for i = 1; i < MAXSQ; i++ {
		k = prime[i]
		for j = sqp[i]; j < MAX; j += k {
			tbl[j] = 1 // Mark multiples of prime[i]
		}
	}

	// Fill the prime array with additional primes
	for sz = MAXSQ, i = 853; i <= MAX; i += 2 {
		if !tbl[i] {
			prime[sz] = i
			sz++
		}
	}
}

// Binary search function to find the index of a prime number
func bsch(x int) int {
	var m, l, r int

	// Perform binary search on the prime array
	for l < r {
		m = (l + r) >> 1 // Calculate mid-point
		if prime[m] == x {
			return m
		}
		if prime[m] < x {
			l = m + 1
		} else {
			r = m
		}
	}
	return l - 1 // Return the index of the largest prime less than x
}

func main() {
	var i, k, p, ans int
	var a, b, j, ll, rr int64

	// Generate the list of prime numbers
	sieve()

	// Read input values A and B
	fmt.Scan(&a, &b)
	a -= b
	if a <= 1 {
		fmt.Println(0)
		return
	}
	if a <= 1 {
		a = 2
	}

	// Find the index of the largest prime less than or equal to sqrt(b/2)
	sz = bsch(int(math.Sqrt(float64(b >> 1))))

	// Initialize the index array to mark valid numbers
	for i = 0; i <= sz; i++ {
		p = prime[i]
		for k = 1; j = p; j *= p; k++ {
			pp[k] = j
		}
		for k--; k > 0; k-- {
			j = pp[k]
			ll = j * (1 + (a - 1) / j)
			rr = j * (b / j)
			for ; ll <= rr; ll += j {
				x := int(ll - a)
				if !idx[x] || base[x] == p {
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

	// Count the valid numbers in the range
	ans = 0
	for i = int(b - a + 1); i > 0; i-- {
		if idx[i] {
			ans++
		}
	}
	fmt.Println(ans)
}

