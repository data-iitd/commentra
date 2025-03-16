
package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1000000007

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	n := nextInt(sc)
	q := nextInt(sc)
	s := nextString(sc)

	r := make([][]int, q)
	for i := 0; i < q; i++ {
		l := nextInt(sc)
		r[i] = []int{l, nextInt(sc)}
	}

	frag := make([]int, n+1)
	rui := make([]int, n+1)
	for i := 2; i <= n; i++ {
		if s[i-2:i] == "AC" {
			frag[i]++
		}
		rui[i] = rui[i-1] + frag[i]
	}

	for _, v := range r {
		l, r := v[0], v[1]
		fmt.Println(rui[r]-rui[l])
	}
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func pow(a, b int) int {
	r := 1
	for i := 0; i < b; i++ {
		r *= a
	}
	return r
}

func abs(x int) int {
	return int(math.Abs(float64(x)))
}

func modpow(a, b, m int) int {
	r := 1
	for i := 0; i < b; i++ {
		r = (r * a) % m
	}
	return r
}

func comb(n, k int) int {
	return fact(n) / (fact(k) * fact(n-k))
}

func perm(n, k int) int {
	return fact(n) / fact(n - k)
}

func fact(n int) int {
	r := 1
	for i := 1; i <= n; i++ {
		r *= i
	}
	return r
}

func gcd(x, y int) int {
	return int(math.Gcd(float64(x), float64(y)))
}

func lcm(x, y int) int {
	return x * y / gcd(x, y)
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(n int) int {
	if n <= 1 {
		return 2
	}
	x := n
	for {
		x++
		if isPrime(x) {
			return x
		}
	}
}

func divisors(n int) []int {
	d := []int{}
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			d = append(d, i)
			if i*i!= n {
				d = append(d, n/i)
			}
		}
	}
	return d
}

func divisorsMap(n int) map[int]int {
	m := map[int]int{}
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			m[i]++
			if i*i!= n {
				m[n/i]++
			}
		}
	}
	return m
}

func inArray(a int, A []int) bool {
	for _, v := range A {
		if v == a {
			return true
		}
	}
	return false
}

func sumArray(A []int) int {
	sum := 0
	for _, v := range A {
		sum += v
	}
	return sum
}

func minArray(A []int) int {
	min := A[0]
	for _, v := range A {
		if v < min {
			min = v
		}
	}
	return min
}

func maxArray(A []int) int {
	max := A[0]
	for _, v := range A {
		if v > max {
			max = v
		}
	}
	return max
}

func powArray(A []int, p int) []int {
	r := make([]int, len(A))
	for i, v := range A {
		r[i] = pow(v, p)
	}
	return r
}

func factArray(n int) []int {
	A := make([]int, n+1)
	A[0] = 1
	for i := 1; i <= n; i++ {
		A[i] = fact(i)
	}
	return A
}

func modInvArray(n int, p int) []int {
	A := make([]int, n+1)
	A[1] = 1
	for i := 2; i <= n; i++ {
		A[i] = modpow(i, p-2, p)
	}
	return A
}

func modInvMap(n int, p int) map[int]int {
	m := make(map[int]int)
	m[1] = 1
	for i := 2; i <= n; i++ {
		m[i] = modpow(i, p-2, p)
	}
	return m
}

func combArray(n int, p int) []int {
	A := make([]int, n+1)
	A[0] = 1
	A[n] = 1
	for i := 1; i < n; i++ {
		A[i] = (A[i-1] * (n-i+1)) / i
	}
	if p > n {
		return []int{}
	}
	return A[:p]
}

func combMap(n int) map[int]int {
	m := make(map[int]int)
	m[0] = 1
	m[n] = 1
	for i := 1; i < n; i++ {
		m[i] = (m[i-1] * (n-i+1)) / i
	}
	return m
}

func permArray(n int, p int) []int {
	A := make([]int, n+1)
	A[0] = 1
	A[n] = 1
	for i := 1; i < n; i++ {
		A[i] = A[i-1] * (n-i+1)
	}
	if p > n {
		return []int{}
	}
	return A[:p]
}

func permMap(n int) map[int]int {
	m := make(map[int]int)
	m[0] = 1
	m[n] = 1
	for i := 1; i < n; i++ {
		m[i] = m[i-1] * (n-i+1)
	}
	return m
}

func isPermutation(s string) bool {
	m := make(map[rune]int)
	for _, v := range s {
		m[v]++
	}
	for _, v := range m {
		if v%2!= 0 {
			return false
		}
	}
	return true
}

func isPalindrome(s string) bool {
	return s == reverse(s)
}

func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

func isPrimeNumber(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func isPalindromeNumber(n int) bool {
	s := fmt.Sprintf("%d", n)
	return isPalindrome(s)
}

func fibonacci(n int) int {
	if n <= 1 {
		return n
	}
	a, b := 0, 1
	for i := 2; i <= n; i++ {
		a, b = b, a+b
	}
	return b
}

func fibonacciArray(n int) []int {
	A := make([]int, n+1)
	A[0] = 0
	A[1] = 1
	for i := 2; i <= n; i++ {
		A[i] = A[i-1] + A[i-2]
	}
	return A
}

func fibonacciMap(n int) map[int]int {
	m := make(map[int]int)
	m[0] = 0
	m[1] = 1
	for i := 2; i <= n; i++ {
		m[i] = m[i-1] + m[i-2]
	}
	return m
}

func lcmArray(A []int) int {
	lcm := A[0]
	for _, v := range A {
		lcm = lcm * v / gcd(lcm, v)
	}
	return lcm
}

func lcmMap(m map[int]int) int {
	lcm := 1
	for _, v := range m {
		lcm = lcm * v / gcd(lcm, v)
	}
	return lcm
}

func gcdArray(A []int) int {
	gcd := A[0]
	for _, v := range A {
		gcd = gcd(gcd, v)
	}
	return gcd
}

func gcdMap(m map[int]int) int {
	gcd := 1
	for _, v := range m {
		gcd = gcd(gcd, v)
	}
	return gcd
}

func isSquare(n int) bool {
	x := int(math.Sqrt(float64(n)))
	return x*x == n
}

func isPowerOfTwo(n int) bool {
	return n > 0 && (n&n-1) == 0
}

func isEven(n int) bool {
	return n%2 == 0
}

func isOdd(n int) bool {
	return n%2!= 0
}

func isPerfectSquare(n int) bool {
	x := int(math.Sqrt(float64(n)))
	return x*x == n
}

func isPrimePower(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			for j := 2; j*j <= i; j++ {
				if i%j == 0 {
					return true
				}
			}
		}
	}
	return false
}

func isPalindromePermutation(s string) bool {
	m := make(map[rune]int)
	for _, v := range s {
		m[v]++
	}
	odd := 0
	for _, v := range m {
		if v%2!= 0 {
			odd++
		}
	}
	return odd <= 1
}

func isAnagram(s1 string, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	m := make(map[rune]int)
	for _, v := range s1 {
		m[v]++
	}
	for _, v := range s2 {
		if m[v] == 0 {
			return false
		}
		m[v]--
	}
	return true
}

func isAnagramMap(s1 string, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	m1 := make(map[rune]int)
	m2 := make(map[rune]int)
	for _, v := range s1 {
		m1[v]++
	}
	for _, v := range s2 {
		m2[v]++
	}
	for k, v := range m1 {
		if m2[k]!= v {
			return false
		}
	}
	return true
}

func isAnagramArray(s1 string, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	A1 := make([]int, 26)
	A2 := make([]int, 26)
	for _, v := range s1 {
		A1[v-'a']++
	}
	for _, v := range s2 {
		A2[v-'a']++
	}
	for i := 0; i < 26; i++ {
		if A1[i]!= A2[i] {
			return false
		}
	}
	return true
}

func isAnagramBit(s1 string, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	x, y := 0, 0
	for _, v := range s1 {
		x |= 1 << (v - 'a')
	}
	for _, v := range s2 {
		y |= 1 << (v - 'a')
	}
	return x == y
}

func isAnagramCount(s1 string, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	A1 := make([]int, 26)
	A2 := make([]int, 26)
	for _, v := range s1 {
		A1[v-'a']++
	}
	for _, v := range s2 {
		A2[v-'a']++
	}
	for i := 0; i < 26; i++ {
		if A1[i]!= A2[i] {
			return false
		}
	}
	return true
}

func isAnagramHash(s1 string, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	h1, h2 := 0, 0
	for _, v := range s1 {
		h1 = h1*31 + int(v)
	}
	for _, v := range s2 {
		h2 = h2*31 + int(v)
	}
	return h1 == h2
}

func isAnagramTrie(s1 string, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	root := &Trie{}
	for _, v := range s1 {
		root.insert(string(v))
	}
	for _, v := range s2 {
		if!root.search(string(v)) {
			return false
		}
	}
	return true
}

type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func (t *Trie) insert(s string) {
	node := t
	for _, v := range s {
		idx := v - 'a'
		if node.children[idx] == nil {
			node.children[idx] = &Trie{}
		}
		node = node.children[idx]
	}
	node.isEnd = true
}

func (t *Trie) search(s string) bool {
	node := t
	for _, v := range s {
		idx := v - 'a'
		if node.children[idx] == nil {
			return false
		}
		node = node.children[idx]
	}
	return node.isEnd
}

func isAnagramSuffixArray(s1 string, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	sa1 := suffixArray(s1)
	sa2 := suffixArray(s2)
	return sa1 == sa2
}

func suffixArray(s string) string {
	n := len(s)
	sa := make([]int, n)
	rank := make([]int, n)
	tmp := make([]int, n)
	for i := 0; i < n; i++ {
		sa[i] = i
	}
	for i := 0; i < n; i++ {
		rank[i] = s[i]
	}
	for k := 1; k < n; k *= 2 {
		for i := 0; i < n; i++ {
			tmp[i] = rank[i]
		}
		Arrays.sort(sa, (a, b) -> Integer.compare(rank[a], rank[b]) );
		}
		for i = 0; i < n; i++ {
			rank[sa[i]] = i;
		}
		for k = 1; k < n; k *= 2 {
			for i = 0; i < n; i++ {
				int j = sa[rank[i]] + k < n; k *= 2 {
			int j = sa[rank[i]] + k < n; k *= 2 {
			int j = sa[rank[i]] + k < n; k *= 2 {
			int j = sa[rank[i]] + k < n; k *= 2 {
				int j = sa[rank[i]] + k < n; k *= 2 {
					int j = sa[rank[i]] + k < n; k *= 2 {
						int j = sa[rank[i]] + k < n; k *= 2 {
							int j = sa[rank[i]] + k < n; k *= 2 {
								int j = sa[rank[i]] + k < n; k *= 2 {
									int j = sa[rank[i]] + k < n; k *= 2 {
										int j = sa[rank[i]] + k < n; k *= 2 {
											int j = sa[rank[i]] + k < n; k *= 2 {
												int j = sa[rank[i]] + k < n; k *= 2 {
													int j = sa[rank[i]] + k < n; k *= 2 {
														int j = sa[rank[i]] + k < n; k *= 2 {
															int j = sa[rank[i]] + k < n; k *= 2 {
																int j = sa[rank[i]] + k < n; k *= 2 {
																	int j = sa[rank[i]] + k < n; k *= 2 {
													int j = sa[rank[i]] + k < n; k *= 2 {
														int j = sa[rank[i]] + k < n; k *= 2 {
															int j = sa[rank[i]] + k < n; k *= 2 {
																int j = sa[rank[i]] + k < n; k *= 2 {
														int j = sa[rank[i]] + k < n; k *= 2 {
															int j = sa[rank[i]] + k < n; k *= 2 {
																int j = sa[rank[i]] + k < n; k *= 