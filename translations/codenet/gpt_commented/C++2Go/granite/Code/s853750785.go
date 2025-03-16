
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Define type aliases for convenience
type ll int64

// Define mathematical constants and macros
const (
	rad_to_deg = 360 / (2 * math.Pi)
	EPS         = 1e-7
	INF         = 1e9
	PI          = math.Pi
	MOD         = 1e9 + 7
)

// Define a pair type for convenience
type P struct {
	first, second int
}

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// Function to calculate the least common multiple (LCM)
func lcd(a, b int) int {
	if b == 0 {
		return a
	}
	return (a / gcd(a, b)) * b
}

// Function to return the digits of a number as a slice
func divnum(num int) []int {
	var dig int
	var p []int
	for num > 0 {
		dig = num % 10
		p = append(p, dig)
		num /= 10
	}
	return p
}

// Function to count the number of digits in a number
func digiter(num int) int {
	var dig int
	var p []int
	for num > 0 {
		dig = num % 10
		p = append(p, dig)
		num /= 10
	}
	return len(p)
}

// Function to convert a string to a slice of integers
func convertstring(s string) []int {
	var d []int
	var n = len(s)
	for i := 0; i < n; i++ {
		d = append(d, int(s[i]-'0'))
	}
	return d
}

// Function to perform prime factorization of a number
func prime_factor(n int) map[int]int {
	m := make(map[int]int)
	for i := 2; i*i <= n; i++ {
		for n%i == 0 {
			m[i]++
			n /= i
		}
	}
	if n!= 1 {
		m[n] = 1
	}
	return m
}

// Function to find all divisors of a number
func divisor(n int) []int {
	var res []int
	for i := 1; i*i <= n; i++ {
		if n%i!= 0 {
			continue
		}
		res = append(res, i)
		if i*i!= n {
			res = append(res, n/i)
		}
	}
	return res
}

// Function to compute x raised to the power n modulo m
func myPow(x, n, m int) int {
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		return myPow(x*x%m, n/2, m)
	} else {
		return x * myPow(x, n-1, m) % m
	}
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
	x int64
}

func (m mint) String() string { return fmt.Sprintf("%d", m.x) }

func newMint(x int64) mint {
	m := mint{x: (x % mod + mod) % mod}
	return m
}

func (m mint) inverse() mint {
	return m.pow(mod - 2)
}

func (m mint) pow(t int64) mint {
	if t == 0 {
		return mint{1}
	}
	a := m.pow(t >> 1)
	a = a.mul(a)
	if t&1 == 1 {
		a = a.mul(m)
	}
	return a
}

func (m mint) mul(n mint) mint {
	return mint{(m.x * n.x) % mod}
}

func (m mint) add(n mint) mint {
	return mint{(m.x + n.x) % mod}
}

func (m mint) sub(n mint) mint {
	return mint{(m.x - n.x + mod) % mod}
}

func (m mint) div(n mint) mint {
	return m.mul(n.inverse())
}

// Overload input/output operators for mint
func (m mint) MarshalText() ([]byte, error) {
	return []byte(m.String()), nil
}

func (m *mint) UnmarshalText(text []byte) error {
	x, err := strconv.ParseInt(string(text), 10, 64)
	if err!= nil {
		return err
	}
	*m = mint{x: x}
	return nil
}

// Structure for combinations (n choose k)
type combination struct {
	fact, ifact []mint
}

func newCombination(n int) combination {
	const limit = 1000005
	fact := make([]mint, limit)
	fact[0] = 1
	for i := 1; i < limit; i++ {
		fact[i] = fact[i-1].mul(mint{int64(i)})
	}
	ifact := make([]mint, limit)
	for i := 0; i < limit; i++ {
		ifact[i] = fact[i].inverse()
	}
	return combination{fact: fact, ifact: ifact}
}

func (c combination) nCr(n, r int) mint {
	if r < 0 || n < r {
		return mint{0}
	}
	return c.fact[n].mul(c.ifact[r]).mul(c.ifact[n-r])
}

// Function to calculate permutations with repetition
func f(n, k int) mint {
	if n < 0 {
		return mint{0}
	}
	// nPk = nCk * k!
	res := c.nCr(n, k)
	res = res.mul(c.fact[k])
	return res
}

// Main function
func main() {
	// Read number of nodes (N) and edges (M)
	N, M := 0, 0
	fmt.Scan(&N, &M)

	// Read heights of each node
	H := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&H[i])
	}

	// Read edges and build the graph
	G := make([][]int, N)
	for i := 0; i < M; i++ {
		u, v := 0, 0
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
