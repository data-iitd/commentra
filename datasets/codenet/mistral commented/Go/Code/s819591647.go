//problem_b.go
// This is the main file for problem B solution

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	//"strings"
)

const (
	constMod = int(1e9) + 7 // Constants definition
)

var (
	sc = bufio.NewScanner(os.Stdin) // Standard input scanner
	wr = bufio.NewWriter(os.Stdout) // Standard output writer
)

// -----------------------------------------

// Function definitions

func getInt() int { // Function to read an integer from standard input
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func getIntSlice(n int) []int { // Function to read n integers and return a slice
	ns := []int{}
	for i := 0; i < n; i++ {
		ns = append(ns, getInt())
	}
	return ns
}

func getString() string { // Function to read a string from standard input
	sc.Scan()
	return sc.Text()
}

func getStringSlice(n int) []string { // Function to read n strings and return a slice
	ss := []string{}
	for i := 0; i < n; i++ {
		ss = append(ss, getString())
	}
	return ss
}

func getStringDoubleSlice(m int, n int) [][]string { // Function to read m strings of length n and return a 2D slice
	sds := [][]string{}
	for i := 0; i < m; i++ {
		ss := getStringSlice(n)
		sds = append(sds, ss)
	}

	return sds

}

// -----------------------------------------

// Sorting functions

func sortIntSlice(ns []int) []int { // Function to sort an integer slice in ascending order
	sort.Sort(sort.IntSlice(ns))
	return ns
}

func sortIntReverseSlice(ns []int) []int { // Function to sort an integer slice in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(ns)))
	return ns
}

// -----------------------------------------

// Mathematical functions

//numAbs(x) = abs(s)
func numAbs(x int) int { // Function to get absolute value of an integer
	if x < 0 {
		return -x
	}

	return x
}

//numModPow(a, n, m) = a^n % m
func numModPow(a int, n int, m int) int { // Function to calculate a^n % m
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

// numGcd(a, b) = gcd(a, b)
func numGcd(a int, b int) int { // Function to calculate the greatest common divisor of a and b
	if b == 0 {
		return a
	}

	return numGcd(b, a%b)
}

// numLcm(a, b) = lcm(a, b)
func numLcm(a int, b int) int { // Function to calculate the least common multiple of a and b
	return a * b / numGcd(a, b)
}

// numModInv(a, p) = a^(-1) % p
func numModInv(a int, p int) int { // Function to calculate the modular inverse of a modulo p
	if a == 1 {
		return 1
	}

	return p - numModInv(p%a, p)*(p/a)%p
}

// numModFrac(n) = n! % constMod
func numModFrac(n int) []int { // Function to calculate n! modulo constMod
	frac := []int{1}

	for i := 1; i <= n; i++ {
		frac = append(frac, i*frac[i-1]%constMod)
	}

	return frac
}

// numModConb(n, r) = nCr % constMod
func numModConb(n int, r int) int { // Function to calculate nCr modulo constMod
	frac := numModFrac(n)

	return (frac[n] / ((frac[n-r] * frac[r]) % constMod)) % constMod
}

// -----------------------------------------

// Main function

func solve() { // Function to solve the problem

	n, m := getInt(), getInt()
	a := getIntSlice(n)

	sum := 0
	for _, v := range a {
		sum += v
	}

	count := 0
	for _, v := range a {
		rate := float64(sum) / float64(4*m)
		if float64(v) >= rate {
			count++
		}
	}

	if count >= m {
		fmt.Fprintln(wr, "Yes")
	} else {
		fmt.Fprintln(wr, "No")
	}

}

// -----------------------------------------

func main() { // Main function
	maxBufSize := int(1e8)
	sc.Buffer(make([]byte, 4096), maxBufSize)
	sc.Split(bufio.ScanWords)
	solve()
	wr.Flush()
}

