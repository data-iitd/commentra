package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

// Define constants and type aliases for convenience
const mod = 998244353

// Function to solve the problem
func solve() {
	var n int
	fmt.Scan(&n) // Read input value for n
	fmt.Println(!n) // Output the negation of n (0 if n is non-zero, 1 if n is zero)
}

// Main function
func main() {
	n := 1 // Initialize n to 1 (can be modified to read input)
	for n > 0 {
		solve() // Call the solve function n times
		n--
	}
}

