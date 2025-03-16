
package main

import (
	"sort"
	"fmt"
	"bufio"
	"os"
	"strconv"
)

//=====I/O=====

// Initialize scanner and writer
var (
	sc = bufio.NewScanner(os.Stdin)
	wr = bufio.NewWriter(os.Stdout)
)

// Function to read an integer from standard input
func scanInt() int {
	sc.Scan()
	// Convert scanned text to integer
	a,_ := strconv.Atoi(sc.Text())
	return a
}

// Function to read an integer64 from standard input
func scanInt64() int64 {
	sc.Scan()
	// Convert scanned text to integer64
	a,_ := strconv.ParseInt(sc.Text(),10,64)
	return a
}

// Function to read n integers from standard input
func scanInts(n int) []int {
	res := make([]int, n)
	// Read n integers and store them in slice res
	for i := 0; i < n; i++ { res[i] = scanInt() }
	return res
}

// Function to print integers to standard output
func printInts(a ...int) {
	// Iterate through slice a and print each integer followed by a space
	for i, e := range a {
		fmt.Fprint(wr, e)
		if i != len(a)-1 { fmt.Fprint(wr, " ") }
	}
	// Print newline character and flush writer buffer
	fmt.Fprintln(wr)
	wr.Flush()
}

//=====main=====

// Set scanner to scan words
func main() {
	sc.Split(bufio.ScanWords)

	// Read an integer n from standard input
	n := scanInt()

	// Read n integers c from standard input and store them in a slice
	c := scanInts(n)

	// Initialize answer variable to 0
	ans := 0

	// Sort slice c in ascending order
	sort.Ints(c)

	// Iterate through slice c and calculate answer
	for i := 0; i < n; i++ {
		// Calculate contribution of current integer to answer
		ans = (ans + (n+1-i)*c[i]%mod)%mod
	}

	// Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
	fmt.Println(ans*modpow(4,n-1)%mod)
}

// Constants
const mod = 1000000007

// Function to calculate modular exponentiation
func modpow(a,n int) int {
	// Initialize result to 1
	res := 1

	// If n is 0, return result
	if n == 0 { return res }

	// If n is 1, return a
	if n == 1 { return a }

	// If n is odd, multiply result with a multiplied by itself recursively
	if n&1 == 1 {
		res = res*a%mod
		a = a*a%mod
		n = n>>1
		res = res*modpow(a,n)%mod
	}

	// If n is even, square result and recursively call function for n/2
	else {
		a = a*a%mod
		n = n>>1
		res = modpow(a,n)%mod
	}

	// Return result
	return res
}

