
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Define a long long integer type for convenience
type ll int64

// Define a macro for a simple loop
func rep(i, l, r ll) {
	for ; i < r; i++ {
	}
}

// Define a macro for a loop with a step
func repp(i, l, r, k ll) {
	for ; i < r; i += k {
	}
}

// Define a large number to represent infinity
const INF = (1 << 62) - (1 << 31)

// Define a macro to get the maximum of two values
func max(p, q ll) ll {
	if p > q {
		return p
	}
	return q
}

// Define a macro to get the minimum of two values
func min(p, q ll) ll {
	if p < q {
		return p
	}
	return q
}

// Define a macro to check if a bit is set in a number
func bit(n, m ll) ll {
	return (n >> m) & 1
}

// Function to sort in ascending order
type upll []ll

func (a upll) Len() int {
	return len(a)
}

func (a upll) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func (a upll) Less(i, j int) bool {
	return a[i] < a[j]
}

// Function to sort in descending order
type downll []ll

func (a downll) Len() int {
	return len(a)
}

func (a downll) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func (a downll) Less(i, j int) bool {
	return a[i] > a[j]
}

// Function to sort an array of long long values in ascending order using sort
func sortup(a []ll) {
	sort.Sort(upll(a))
}

// Function to sort an array of long long values in descending order using sort
func sortdown(a []ll) {
	sort.Sort(downll(a))
}

// Function to perform modular exponentiation
func pom(a, n, m ll) ll {
	x := 1
	a %= m
	for ; n > 0; n /= 2 {
		if n&1 == 1 {
			x = x*a % m
		}
		a = a*a % m
	}
	return x
}

// Define a modulo value
const MOD = 1000000007

// Function to compute the modular multiplicative inverse
func invp(a, p ll) ll {
	return pom(a, p-2, p)
}

// Define a structure to hold edge information
type E struct {
	p ll
	i int
	s string
}

// Function to sort edges based on the string and then by the long long value
type esort []E

func (a esort) Len() int {
	return len(a)
}

func (a esort) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func (a esort) Less(i, j int) bool {
	cmp := strings.Compare(a[i].s, a[j].s)
	if cmp != 0 {
		return cmp < 0
	}
	if a[i].p < a[j].p {
		return true
	}
	return false
}

// Array to hold edge data
var data []E

// Variables to hold the number of edges
var n, m ll

// Main function
func main() {
	// Read the number of edges
	fmt.Scan(&n)

	// Read each edge's string and long long value, and store the index
	data = make([]E, n)
	for i := ll(0); i < n; i++ {
		fmt.Scan(&data[i].s, &data[i].p)
		data[i].i = int(i)
	}

	// Sort the edges using sort and the custom esort function
	sort.Sort(esort(data))

	// Print the indices of the edges in the sorted order
	for _, e := range data {
		fmt.Println(e.i + 1)
	}
}

