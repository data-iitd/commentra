
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	n int
	m int
	a []int
)

// Function to read input
func readInput() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read n
	line, _ := reader.ReadString('\n')
	n, _ = strconv.Atoi(strings.TrimSpace(line))
	// Read m
	line, _ = reader.ReadString('\n')
	m, _ = strconv.Atoi(strings.TrimSpace(line))
	// Read a
	a = make([]int, n)
	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		a[i], _ = strconv.Atoi(strings.TrimSpace(line))
	}
}

// Function to write output
func writeOutput(ans int) {
	// Write output to stdout
	fmt.Println(ans)
}

// Function to solve the problem
func solve() int {
	// Initialize variables
	ans := 0
	base := 0
	dp := make(map[int]int)

	// Process each element in array a
	for i := 0; i < n; i++ {
		// Update base value
		base = (base - a[i] % m + m) % m
		// Update hashmap with current base and its count
		dp[base+a[i]%m]++
		// Update answer variable
		ans += dp[base]
	}

	// Return the answer
	return ans
}

// Main function
func main() {
	// Read input
	readInput()
	// Solve the problem
	ans := solve()
	// Write output
	writeOutput(ans)
}

// 