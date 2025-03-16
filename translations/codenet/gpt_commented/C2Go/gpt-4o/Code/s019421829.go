package main

import (
	"fmt"
	"math"
)

const MAX = 707106 // Define the maximum value for the sieve (sqrt(10^12/2))

var tbl [MAX + 1]bool // Array to mark non-prime numbers

var sz int           // Variable to hold the size of the prime array
var prime = []int{   // Predefined array of prime numbers
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

var sqp = []int{ // Array to hold squares of the first 146 prime numbers
	4, 9, 25, 49, 121, 169, 289, 361, 529, 841, 961,
	1369, 1681, 1849, 2209, 2809, 3481, 3721, 4489, 5041,
	5329, 6241, 6889, 7921, 9409, 10201, 10609, 11449, 11881, 12769,
	16129, 17161, 18769, 19321, 22201, 22801, 24649, 26569, 27889, 29929,
	32041, 32761, 36481, 37249, 38809, 39601, 44521, 49729, 51529, 52441, 54289,
	57121, 58081, 63001, 66049, 69169, 72361, 73441, 76729, 78961, 80089, 85849,
	94249, 96721, 97969, 100489, 109561, 113569, 120409, 121801, 124609, 128881,
	134689, 139129, 143641, 146689, 151321, 157609, 160801, 167281, 175561, 177241,
	185761, 187489, 192721, 196249, 201601, 208849, 212521, 214369, 218089, 229441,
	237169, 241081, 249001, 253009, 259081, 271441, 273529, 292681, 299209, 310249,
	316969, 323761, 326041, 332929, 344569, 351649, 358801, 361201, 368449, 375769,
	380689, 383161, 398161, 410881, 413449, 418609, 426409, 434281, 436921, 452929,
	458329, 466489, 477481, 491401, 502681, 516961, 528529, 537289, 546121, 552049,
	564001, 573049, 579121, 591361, 597529, 619369, 635209, 654481, 657721, 674041,
	677329, 683929, 687241, 703921, 727609,
}

// Function to generate prime numbers using the Sieve of Eratosthenes
func sieve() {
	for i := 1; i < 147; i++ {
		k := prime[i]
		for j := sqp[i]; j < MAX; j += k {
			tbl[j] = true // Mark multiples of prime[i]
		}
	}

	// Fill the prime array with additional primes
	for sz = 146; sz < len(prime); sz++ {
		i := prime[sz-1] + 2
		for ; i <= MAX; i += 2 {
			if !tbl[i] {
				prime = append(prime, i) // Add odd primes
			}
		}
	}
}

// Binary search function to find the index of a prime number
func bsch(x int) int {
	l, r := 0, sz
	for l < r {
		m := (l + r) >> 1 // Calculate mid-point
		if prime[m] == x {
			return m // Found the prime
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
	var A, B int64
	var a, b int64
	var ans int

	// Generate the list of prime numbers
	sieve()

	// Read input values A and B
	fmt.Scanf("%d %d", &A, &B)
	a = A - B // Calculate the difference
	b = A + B // Calculate the sum
	if b <= 1 {
		fmt.Println(0)
		return
	}
	if a <= 1 {
		a = 2
	}

	// Find the index of the largest prime less than or equal to sqrt(b/2)
	sz = bsch(int(math.Sqrt(float64(b >> 1))))

	// Initialize the index array to mark valid numbers
	idx := make([]int, 1000002)
	base := make([]int, 1000002)
	for i := range idx {
		idx[i] = 1
	}

	pp := make([]int64, 41) // Array to hold powers of 2 up to 2^40
	for i := 0; i <= sz; i++ {
		p := prime[i] // Get the current prime
		for k, j := 1, int64(p); j <= b; j *= int64(p) {
			pp[k] = j
			k++
		}
		for k--; k > 0; k-- {
			j := pp[k]
			ll := j * (1 + (a - 1) / j)
			rr := j * (b / j)
			for ll <= rr {
				x := int(ll - a) // Calculate the index in the base array
				if idx[x] == 0 || base[x] == p {
					ll += j
					continue
				}
				if idx[x] < k {
					idx[x] = 0 // Mark as invalid if fewer powers
				} else {
					base[x] = p
					idx[x] = k // Update base and index
				}
				ll += j
			}
		}
	}

	// Count the valid numbers in the range
	for i := int(b - a + 1); i > 0; i-- {
		if idx[i] != 0 {
			ans++
		}
	}
	fmt.Println(ans) // Output the result
}

// <END-OF-CODE>
