// Include necessary headers for input/output, data manipulation, and other functionalities
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Define constants and data structures
const (
	MAX_L = 22
	INF   = 1145141919
	MOD   = 1000000007
)

type P struct {
	x, y int
}

type Graph [][]P

var (
	N, Q, K int
	G       Graph
	U       [MAX_L][100000]int
	R       [100000]int
	L       [100000]int
)

// Depth-First Search (DFS) function to traverse the graph and populate the ancestor matrix and rank array
func dfs(x, p, r int, l int64) {
	U[0][x] = p
	R[x] = r
	L[x] = l
	for _, pp := range G[x] {
		t := pp.x
		if t == p {
			continue
		}
		dfs(t, x, r+1, l+int64(pp.y))
	}
}

// Lowest Common Ancestor (LCA) function to find the lowest common ancestor of two nodes
func lca(a, b int) int {
	if R[a] > R[b] {
		a, b = b, a
	}
	for i := 0; i < MAX_L; i++ {
		if (R[a]-R[b])>>i&1 == 1 {
			b = U[i][b]
		}
	}
	if a == b {
		return a
	}
	for i := MAX_L - 1; i >= 0; i-- {
		if U[i][a] != U[i][b] {
			a, b = U[i][a], U[i][b]
		}
	}
	return U[0][a]
}

// Distance calculation function to find the distance between two nodes
func dist(x, y int) int64 {
	g := lca(x, y)
	return L[x] + L[y] - 2*L[g]
}

// Main function to read input, initialize the graph, call dfs to populate the ancestor matrix, and process queries
func main() {
	var err error
	N, err = strconv.Atoi(readLine())
	if err != nil {
		panic(err)
	}
	G = make(Graph, N)
	rep(i, N-1) {
		var a, b, c int
		fmt.Sscanf(readLine(), "%d %d %d", &a, &b, &c)
		a--
		b--
		G[a] = append(G[a], P{b, c})
		G[b] = append(G[b], P{a, c})
	}
	rep(i, MAX_L) {
		rep(j, N) {
			U[i][j] = -1
		}
	}
	dfs(0, -1, 0, 0)
	for i := 0; i < MAX_L-1; i++ {
		rep(j, N) {
			if U[i][j] == -1 {
				U[i+1][j] = -1
			} else {
				U[i+1][j] = U[i][U[i][j]]
			}
		}
	}
	fmt.Sscanf(readLine(), "%d %d", &Q, &K)
	K--
	rep(i, Q) {
		var x, y int
		fmt.Sscanf(readLine(), "%d %d", &x, &y)
		x--
		y--
		fmt.Println(dist(x, K) + dist(K, y))
	}
}

// Utility functions
func readLine() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func rep(i, n int) {
	for ; i < n; i++ {
	}
}

func all(c []int) []int {
	return c
}

func uniq(c []int) []int {
	sort.Ints(c)
	j := 0
	for i := 1; i < len(c); i++ {
		if c[j] != c[i] {
			j++
		}
		c[j] = c[i]
	}
	return c[:j+1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func pow(a, b int) int {
	r := 1
	for ; b > 0; b-- {
		r *= a
	}
	return r
}

func bitLen(x int) int {
	r := 0
	for ; x > 0; x >>= 1 {
		r++
	}
	return r
}

func popCount(x int) int {
	r := 0
	for ; x > 0; x &= x - 1 {
		r++
	}
	return r
}

func isPrime(x int) bool {
	if x <= 1 {
		return false
	}
	for i := 2; i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

func isEven(x int) bool {
	return x%2 == 0
}

func isOdd(x int) bool {
	return x%2 == 1
}

func isPowerOfTwo(x int) bool {
	return x > 0 && x&(x-1) == 0
}

func isPerfectSquare(x int) bool {
	r := int(sqrt(float64(x)))
	return r*r == x
}

func isPalindrome(s string) bool {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		if s[i] != s[j] {
			return false
		}
	}
	return true
}

func isPermutation(a, b string) bool {
	if len(a) != len(b) {
		return false
	}
	c := make([]int, 26)
	for _, v := range a {
		c[v-'a']++
	}
	for _, v := range b {
		c[v-'a']--
		if c[v-'a'] < 0 {
			return false
		}
	}
	return true
}

func isSubsequence(a, b string) bool {
	i, j := 0, 0
	for i < len(a) && j < len(b) {
		if a[i] == b[j] {
			i++
		}
		j++
	}
	return i == len(a)
}

func isSubstring(a, b string) bool {
	return strings.Contains(b, a)
}

func isSuffix(a, b string) bool {
	return strings.HasSuffix(b, a)
}

func isPrefix(a, b string) bool {
	return strings.HasPrefix(b, a)
}

func isContain(s string, c byte) bool {
	return strings.ContainsRune(s, rune(c))
}

func isContainAny(s string, c string) bool {
	return strings.ContainsAny(s, c)
}

func isContainAll(s string, c string) bool {
	for _, v := range c {
		if !isContain(s, byte(v)) {
			return false
		}
	}
	return true
}

func isContainOnly(s string, c string) bool {
	for _, v := range s {
		if !isContain(c, byte(v)) {
			return false
		}
	}
	return true
}

func isContainNone(s string, c string) bool {
	for _, v := range s {
		if isContain(c, byte(v)) {
			return false
		}
	}
	return true
}

func isContainAnyOf(s string, c string) bool {
	for _, v := range s {
		if isContain(c, byte(v)) {
			return true
		}
	}
	return false
}

func isContainAllOf(s string, c string) bool {
	for _, v := range c {
		if !isContain(s, byte(v)) {
			return false
		}
	}
	return true
}

func isContainOnlyOf(s string, c string) bool {
	for _, v := range s {
		if !isContain(c, byte(v)) {
			return false
		}
	}
	return true
}

func isContainNoneOf(s string, c string) bool {
	for _, v := range s {
		if isContain(c, byte(v)) {
			return false
		}
	}
	return true
}

func isContainAnyOfRune(s string, c []rune) bool {
	for _, v := range s {
		for _, w := range c {
			if v == w {
				return true
			}
		}
	}
	return false
}

func isContainAllOfRune(s string, c []rune) bool {
	for _, v := range c {
		if !isContainRune(s, v) {
			return false
		}
	}
	return true
}

func isContainOnlyOfRune(s string, c []rune) bool {
	for _, v := range s {
		if !isContainRune(c, v) {
			return false
		}
	}
	return true
}

func isContainNoneOfRune(s string, c []rune) bool {
	for _, v := range s {
		if isContainRune(c, v) {
			return false
		}
	}
	return true
}

func isContainRune(s string, c rune) bool {
	for _, v := range s {
		if v == c {
			return true
		}
	}
	return false
}

func isContainAnyOfByte(s string, c []byte) bool {
	for _, v := range s {
		for _, w := range c {
			if v == w {
				return true
			}
		}
	}
	return false
}

func isContainAllOfByte(s string, c []byte) bool {
	for _, v := range s {
		if !isContainByte(c, v) {
			return false
		}
	}
	return true
}

func isContainOnlyOfByte(s string, c []byte) bool {
	for _, v := range s {
		if !isContainByte(c, v) {
			return false
		}
	}
	return true
}

func isContainNoneOfByte(s string, c []byte) bool {
	for _, v := range s {
		if isContainByte(c, v) {
			return false
		}
	}
	return true
}

func isContainByte(c []byte, v byte) bool {
	for _, w := range c {
		if v == w {
			return true
		}
	}
	return false
}

func isContainAnyOfInt(s []int, c []int) bool {
	for _, v := range s {
		for _, w := range c {
			if v == w {
				return true
			}
		}
	}
	return false
}

func isContainAllOfInt(s []int, c []int) bool {
	for _, v := range s {
		if !isContainInt(c, v) {
			return false
		}
	}
	return true
}

func isContainOnlyOfInt(s []int, c []int) bool {
	for _, v := range s {
		if !isContainInt(c, v) {
			return false
		}
	}
	return true
}

func isContainNoneOfInt(s []int, c []int) bool {
	for _, v := range s {
		if isContainInt(c, v) {
			return false
		}
	}
	return true
}

func isContainInt(c []int, v int) bool {
	for _, w := range c {
		if v == w {
			return true
		}
	}
	return false
}

func isContainAnyOfInt64(s []int64, c []int64) bool {
	for _, v := range s {
		for _, w := range c {
			if v == w {
				return true
			}
		}
	}
	return false
}

func isContainAllOfInt64(s []int64, c []int64) bool {
	for _, v := range s {
		if !isContainInt64(c, v) {
			return false
		}
	}
	return true
}

func isContainOnlyOfInt64(s []int64, c []int64) bool {
	for _, v := range s {
		if !isContainInt64(c, v) {
			return false
		}
	}
	return true
}

func isContainNoneOfInt64(s []int64, c []int64) bool {
	for _, v := range s {
		if isContainInt64(c, v) {
			return false
		}
	}
	return true
}

func isContainInt64(c []int64, v int64) bool {
	for _, w := range c {
		if v == w {
			return true
		}
	}
	return false
}

func isContainAnyOfFloat64(s []float64, c []float64) bool {
	for _, v := range s {
		for _, w := range c {
			if v == w {
				return true
			}
		}
	}
	return false
}

func isContainAllOfFloat64(s []float64, c []float64) bool {
	for _, v := range s {
		if !isContainFloat64(c, v) {
			return false
		}
	}
	return true
}

func isContainOnlyOfFloat64(s []float64, c []float64) bool {
	for _, v := range s {
		if !isContainFloat64(c, v) {
			return false
		}
	}
	return true
}

func isContainNoneOfFloat64(s []float64, c []float64) bool {
	for _, v := range s {
		if isContainFloat64(c, v) {
			return false
		}
	}
	return true
}

func isContainFloat64(c []float64, v float64) bool {
	for _, w := range c {
		if v == w {
			return true
		}
	}
	return false
}

func isContainAnyOfString(s []string, c []string) bool {
	for _, v := range s {
		for _, w := range c {
			if v == w {
				return true
			}
		}
	}
	return false
}

func isContainAllOfString(s []string, c []string) bool {
	for _, v := range s {
		if !isContainString(c, v) {
			return false
		}
	}
	return true
}

func isContainOnlyOfString(s []string, c []string) bool {
	for _, v := range s {
		if !isContainString(c, v) {
			return false
		}
	}
	return true
}

func isContainNoneOfString(s []string, c []string) bool {
	for _, v := range s {
		if isContainString(c, v) {
			return false
		}
	}
	return true
}

func isContainString(c []string, v string) bool {
	for _, w := range c {
		if v == w {
			return true
		}
	}
	return false
}

func isContainAnyOfBool(s []bool, c []bool) bool {
	for _, v := range s {
		for _, w := range c {
			if v == w {
				return true
			}
		}
	}
	return false
}

func isContainAllOfBool(s []bool, c []bool) bool {
	for _, v := range s {
		if !isContainBool(c, v) {
			return false
		}
	}
	return true
}

func isContainOnlyOfBool(s []bool, c []bool) bool {
	for _, v := range s {
		if !isContainBool(c, v) {
			return false
		}
	}
	return true
}

func isContainNoneOfBool(s []bool, c []bool) bool {
	for _, v := range s {
		if isContainBo