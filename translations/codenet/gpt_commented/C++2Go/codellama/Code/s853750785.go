
package main

import (
	"fmt"
)

// Define type aliases for convenience
type ll int

// Define mathematical constants and macros
const (
	rad_to_deg = 360 / (2 * math.Pi)
	EPS        = 1e-7
	INF        = 1e9
	PI         = math.Acos(-1)
)

// Define a pair type for convenience
type P struct {
	x, y ll
}

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b ll) ll {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to calculate the least common multiple (LCM)
func lcd(a, b ll) ll {
	if b == 0 {
		return a
	}
	return (a / gcd(a, b)) * b
}

// Function to return the digits of a number as a vector
func divnum(num ll) []int {
	var dig int
	var p []int
	for num > 0 {
		dig = int(num % 10)
		p = append(p, dig)
		num /= 10
	}
	return p
}

// Function to count the number of digits in a number
func digiter(num ll) int {
	var dig int
	var p []int
	for num > 0 {
		dig = int(num % 10)
		p = append(p, dig)
		num /= 10
	}
	return len(p)
}

// Function to convert a string to a vector of integers
func convertstring(s string) []int {
	var d []int
	var n = len(s)
	for i := 0; i < n; i++ {
		d = append(d, int(s[i])-'0')
	}
	return d
}

// Function to perform prime factorization of a number
func prime_factor(n ll) map[ll]int {
	var ret = make(map[ll]int)
	for i := 2; i*i <= n; i++ {
		for n%i == 0 {
			ret[i]++
			n /= i
		}
	}
	if n != 1 {
		ret[n] = 1
	}
	return ret
}

// Function to find all divisors of a number
func divisor(n ll) []ll {
	var res []ll
	for i := 1; i*i <= n; i++ {
		if n%i != 0 {
			continue
		}
		res = append(res, i)
		if i*i != n {
			res = append(res, n/i)
		}
	}
	return res
}

// Function to compute x raised to the power n modulo m
func myPow(x, n, m ll) ll {
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		return myPow(x*x%m, n/2, m)
	}
	return x * myPow(x, n-1, m) % m
}

// Function to generate a list of prime numbers using the Sieve of Eratosthenes
func Eratosthenes(N int) []int {
	var is_prime = make([]bool, N+1)
	for i := 0; i <= N; i++ {
		is_prime[i] = true
	}
	var P []int
	for i := 2; i <= N; i++ {
		if is_prime[i] {
			for j := 2 * i; j <= N; j += i {
				is_prime[j] = false
			}
			P = append(P, i)
		}
	}
	return P
}

// Structure for modular arithmetic
const mod = 1e9 + 7
type mint struct {
	x ll
}

// Overload input/output operators for mint
func (a mint) String() string {
	return fmt.Sprintf("%d", a.x)
}

// Define a structure for combinations (n choose k)
type combination struct {
	fact, ifact []mint
}

// Function to generate a list of prime numbers using the Sieve of Eratosthenes
func (comb *combination) init(N int) {
	comb.fact = make([]mint, N+1)
	comb.ifact = make([]mint, N+1)
	assert(N < mod)
	comb.fact[0] = 1
	for i := 1; i <= N; i++ {
		comb.fact[i] = comb.fact[i-1] * mint(i)
	}
	comb.ifact[N] = comb.fact[N].inv()
	for i := N; i >= 1; i-- {
		comb.ifact[i-1] = comb.ifact[i] * mint(i)
	}
}

// Function to calculate permutations with repetition
func (comb *combination) f(n, k ll) mint {
	if k < 0 || k > n {
		return 0
	}
	// nPk = nCk * k!
	res := comb.fact[n] * comb.ifact[k] * comb.ifact[n-k]
	return res
}

// Main function
func main() {
	// Read number of nodes (N) and edges (M)
	fmt.Scan(&N, &M)

	// Read heights of each node
	H := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&H[i])
	}

	// Read edges and build the graph
	G := make([][]int, N)
	for i := 0; i < M; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u--
		v--
		G[u] = append(G[u], v)
		G[v] = append(G[v], u)
	}

	ans := 0 // Variable to count the number of nodes that are taller than all their neighbors

	// Iterate through each node to check if it is taller than all its neighbors
	for u := 0; u < N; u++ {
		flag := true // Flag to check if the current node is taller
		for _, v := range G[u] {
			if H[u] <= H[v] {
				flag = false // If any neighbor is taller or equal, set flag to false
			}
		}
		if flag {
			ans++ // If the flag is still true, increment the answer
		}
	}

	// Output the result
	fmt.Println(ans)
}

