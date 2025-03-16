package main

import (
	"fmt"
	"math"
)

// Define type aliases for convenience
type ll int

// Define mathematical constants and macros
const (
	EPS  = 1e-7
	INF  = 1e9
	PI   = math.Pi
	MOD  = 1e9 + 7
	LINF = 1000000000000000000
)

// Define a pair type for convenience
type P struct {
	first  ll
	second ll
}

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b ll) ll {
	if b == 0 {
		return a
	}
	return gcd(b, a % b)
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
	for _, ch := range s {
		d = append(d, int(ch-'0'))
	}
	return d
}

// Function to perform prime factorization of a number
func primeFactor(n ll) map[ll]int {
	ret := make(map[ll]int)
	for i := 2; i*i <= n; i++ {
		for n%i == 0 {
			ret[ll(i)]++
			n /= ll(i)
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
		res = append(res, ll(i))
		if i*i != n {
			res = append(res, n/ll(i))
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
	isPrime := make([]bool, N+1)
	for i := 0; i <= N; i++ {
		isPrime[i] = true
	}
	var P []int
	for i := 2; i <= N; i++ {
		if isPrime[i] {
			for j := 2 * i; j <= N; j += i {
				isPrime[j] = false
			}
			P = append(P, i)
		}
	}
	return P
}

// Define a structure for modular arithmetic
const mod = MOD

type mint struct {
	x ll
}

func newMint(x ll) *mint {
	return &mint{x: (x%mod + mod) % mod}
}

func (m *mint) neg() *mint {
	return &mint{x: -m.x}
}

func (m *mint) add(a *mint) *mint {
	if (m.x += a.x) >= mod {
		m.x -= mod
	}
	return m
}

func (m *mint) sub(a *mint) *mint {
	if (m.x += mod - a.x) >= mod {
		m.x -= mod
	}
	return m
}

func (m *mint) mul(a *mint) *mint {
	m.x = m.x * a.x % mod
	return m
}

func (m *mint) pow(t ll) *mint {
	if t == 0 {
		return newMint(1)
	}
	a := m.pow(t >> 1)
	a.mul(a)
	if t&1 == 1 {
		a.mul(m)
	}
	return a
}

// for prime mod
func (m *mint) inv() *mint {
	return m.pow(mod - 2)
}

func (m *mint) div(a *mint) *mint {
	return m.mul(a.inv())
}

// Structure for combinations (n choose k)
type combination struct {
	fact, ifact []mint
}

func newCombination(n int) *combination {
	fact := make([]mint, n+1)
	ifact := make([]mint, n+1)
	fact[0] = *newMint(1)
	for i := 1; i <= n; i++ {
		fact[i].x = fact[i-1].x * ll(i) % mod
	}
	ifact[n] = *fact[n].inv()
	for i := n; i >= 1; i-- {
		ifact[i-1].x = ifact[i].x * ll(i) % mod
	}
	return &combination{fact, ifact}
}

func (c *combination) operator(n, k int) mint {
	if k < 0 || k > n {
		return *newMint(0)
	}
	return c.fact[n].mul(&c.ifact[k]).mul(&c.ifact[n-k])
}

// Function to calculate permutations with repetition
func f(n, k int) mint {
	if n < 0 {
		return *newMint(0)
	}
	res := c.operator(n, k)
	res.x = res.x * c.fact[k].x % mod
	return res
}

// Main function
var (
	N, M  int
	H      []int
	G      [][]int
	c      = newCombination(1000005)
)

func main() {
	// Read number of nodes (N) and edges (M)
	fmt.Scan(&N, &M)

	// Read heights of each node
	H = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&H[i])
	}

	// Read edges and build the graph
	G = make([][]int, N)
	for i := 0; i < M; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u--
		v--
		G[u] = append(G[u], v)
		G[v] = append(G[v], u)
	}

	ans := 0

	// Iterate through each node to check if it is taller than all its neighbors
	for u := 0; u < N; u++ {
		flag := true
		for _, v := range G[u] {
			if H[u] <= H[v] {
				flag = false
				break
			}
		}
		if flag {
			ans++
		}
	}

	// Output the result
	fmt.Println(ans)
}

