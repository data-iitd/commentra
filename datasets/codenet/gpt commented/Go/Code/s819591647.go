// problem_b.go

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	//"strings"
)

// Define a constant for modulus operation
const (
	constMod = int(1e9) + 7
)

// Initialize scanner and writer for input and output
var (
	sc = bufio.NewScanner(os.Stdin)
	wr = bufio.NewWriter(os.Stdout)
)

// -----------------------------------------

// getInt reads a single integer from input
func getInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// getIntSlice reads n integers from input and returns them as a slice
func getIntSlice(n int) []int {
	ns := []int{}
	for i := 0; i < n; i++ {
		ns = append(ns, getInt())
	}
	return ns
}

// getIntDoubleSlice reads m slices of n integers from input and returns them as a 2D slice
func getIntDoubleSlice(m int, n int) [][]int {
	var nds [][]int
	for i := 0; i < m; i++ {
		ns := getIntSlice(n)
		nds = append(nds, ns)
	}

	return nds
}

// getString reads a single string from input
func getString() string {
	sc.Scan()
	return sc.Text()
}

// getStringSlice reads n strings from input and returns them as a slice
func getStringSlice(n int) []string {
	ss := []string{}
	for i := 0; i < n; i++ {
		ss = append(ss, getString())
	}
	return ss
}

// getStringDoubleSlice reads m slices of n strings from input and returns them as a 2D slice
func getStringDoubleSlice(m int, n int) [][]string {
	sds := [][]string{}
	for i := 0; i < m; i++ {
		ss := getStringSlice(n)
		sds = append(sds, ss)
	}

	return sds
}

// -----------------------------------------

// Sort Functions

// sortIntSlice sorts a slice of integers in ascending order
func sortIntSlice(ns []int) []int {
	sort.Sort(sort.IntSlice(ns))
	return ns
}

// sortIntReverseSlice sorts a slice of integers in descending order
func sortIntReverseSlice(ns []int) []int {
	sort.Sort(sort.Reverse(sort.IntSlice(ns)))
	return ns
}

// -----------------------------------------

// Number Functions

// numAbs returns the absolute value of an integer x
func numAbs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// numModPow computes a^n % m using modular exponentiation
func numModPow(a int, n int, m int) int {
	result := 1

	for n > 0 {
		if n%2 == 1 {
			result = (result * a) % m
		}
		a = (a * a) % m
		n >>= 1
	}

	return result
}

// numGcd computes the greatest common divisor of a and b
func numGcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return numGcd(b, a%b)
}

// numLcm computes the least common multiple of a and b
func numLcm(a int, b int) int {
	return a * b / numGcd(a, b)
}

// numModInv computes the modular inverse of a under modulo p
func numModInv(a int, p int) int {
	if a == 1 {
		return 1
	}
	return p - numModInv(p%a, p)*(p/a)%p
}

// numModFrac computes factorials modulo constMod up to n
func numModFrac(n int) []int {
	frac := []int{1}

	for i := 1; i <= n; i++ {
		frac = append(frac, i*frac[i-1]%constMod)
	}

	return frac
}

// numModConb computes nCr % constMod using precomputed factorials
func numModConb(n int, r int) int {
	frac := numModFrac(n)
	return (frac[n] / ((frac[n-r] * frac[r]) % constMod)) % constMod
}

// -----------------------------------------

// solve function implements the main logic of the problem
func solve() {
	// Read n and m from input
	n, m := getInt(), getInt()
	// Read n integers into slice a
	a := getIntSlice(n)

	// Calculate the sum of all elements in a
	sum := 0
	for _, v := range a {
		sum += v
	}

	// Count how many elements in a meet the required rate
	count := 0
	for _, v := range a {
		rate := float64(sum) / float64(4*m)
		if float64(v) >= rate {
			count++
		}
	}

	// Output "Yes" if count is greater than or equal to m, otherwise "No"
	if count >= m {
		fmt.Fprintln(wr, "Yes")
	} else {
		fmt.Fprintln(wr, "No")
	}
}

// -----------------------------------------

// main function initializes the program and calls solve
func main() {
	// Set a maximum buffer size for input
	maxBufSize := int(1e8)
	sc.Buffer(make([]byte, 4096), maxBufSize)
	sc.Split(bufio.ScanWords)
	// Call the solve function to execute the main logic
	solve()
	// Flush the writer to output results
	wr.Flush()
}
