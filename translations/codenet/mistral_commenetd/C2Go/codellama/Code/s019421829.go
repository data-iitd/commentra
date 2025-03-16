#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX  707106			// sqrt(10^12/2)
var tbl [MAX+1]byte

var sz int					// max sz = 57084, prime[0] = 2, prime[57083] = 707099
var prime [57100]int = {  	// prime[146] = 853, prime[147] = 857
  2, 3,  5,  7, 11, 13, 17, 19, 23, 29, 
 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
 73, 79, 83, 89, 97,101,103,107,109,113, 
127,131,137,139,149,151,157,163,167,173,
179,181,191,193,197,199,211,223,227,229, 
233,239,241,251,257,263,269,271,277,281, 
283,293,307,311,313,317,331,337,347,349, 
353,359,367,373,379,383,389,397,401,409, 
419,421,431,433,439,443,449,457,461,463, 
467,479,487,491,499,503,509,521,523,541, 
547,557,563,569,571,577,587,593,599,601, 
607,613,617,619,631,641,643,647,653,659, 
661,673,677,683,691,701,709,719,727,733, 
739,743,751,757,761,769,773,787,797,809, 
811,821,823,827,829,839,853 }

func sieve() {
	var i, j, k int

	// Sieve of Eratosthenes algorithm to find prime numbers up to sqrt(MAX)
	for i = 1; i < 147; i++ {
		k = prime[i]			// Get the current prime number
		for j = sqp[i]; j < MAX; j += k { tbl[j] = 1 }	// Mark all multiples of 'k' as composite in 'tbl' array
	}
	// Find all prime numbers greater than sqrt(MAX)
	for sz = 146, i = 853; i <= MAX; i += 2 {
		if !tbl[i] { prime[sz] = i; sz++ }	// If 'i' is not marked as composite, it is a prime number
	}
//	fmt.Printf("sz %d, prime[%d]=%d\n", sz, sz-1, prime[sz-1])
//	        sz 57084, prime[57083]=707099
}

var base [1000002]int
var idx [1000002]int
var pp [41]int		// 2^40 = 1099511627776 >= 10^12

func bsch(x int) int {
	var m, l, r int

	// Binary search algorithm to find the index of the largest prime number 'p' such that 'p^2 <= x'
	for l < r {
		m = (l + r) >> 1		// Calculate the middle index 'm'
		if prime[m] == x { return m }	// If 'x' is a prime number, return its index
		if prime[m] < x { l = m + 1 }	// If 'prime[m]' is smaller than 'x', 'l' should be updated
		else { r = m }					// Otherwise, 'r' should be updated
	}
	return l-1					// Return the index of the largest prime number 'p' such that 'p^2 <= x'
}

func main() {
	var i, k, p, ans int
	var A, B, a, b, j, ll, rr int64

	sieve()					// Call the Sieve of Eratosthenes algorithm to find prime numbers

	fmt.Scanf("%d%d", &A, &B)	// Read two integers 'A' and 'B' from the standard input
	a = A-B; b = A+B			// Calculate 'a' = 'A' - 'B' and 'b' = 'A' + 'B'
	if b <= 1 { fmt.Println(0); return }	// If 'b' is less than or equal to 1, output '0' and terminate the program
	if a <= 1 { a = 2 }			// If 'a' is less than or equal to 1, set it to 2

	sz = bsch((int)(math.Sqrt(float64(b >> 1))))	// Find the largest prime number 'p' such that 'p^2 <= b' using binary search

	for i = 0; i <= sz; i++ {
		p = prime[i]			// Get the current prime number
		for k = 1; j = p; j *= p { pp[k] = j }	// Calculate all powers of 'p' less than or equal to 'b'
		for ; k--; {
			j = pp[k], ll = j*(1+(a-1)/j), rr = j*(b/j)	// Calculate the lower and upper bounds of the segment to search for 'a' in
			for ; ll <= rr; ll += j {
				x := (int)(ll-a)	// Calculate the index 'x' of the segment
				if !idx[x] || base[x] == p { continue }	// If 'x' is already processed or the prime number at 'x' is the same as 'p', skip it
				base[x] = p, idx[x] = k	// Otherwise, set the prime number at 'x' to 'p' and its index to 'k'
			}
		}
	}

	ans = 0; i = (int)(b-a+1)	// Initialize 'ans' to 0 and the loop counter 'i' to the number of segments
	for ; i--; { if idx[i] { ans++ } }	// Increment 'ans' if the current segment has been processed
	fmt.Println(ans)				// Output the result 'ans' and terminate the program
}

