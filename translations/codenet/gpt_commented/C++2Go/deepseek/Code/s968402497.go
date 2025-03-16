package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

const (
	mod    = 1000000007
	mod9   = 998244353
	eps    = 1e-7
	INF    = 0x3f3f3f3f
	inf    = 0x3f3f3f3f3f3f3f3f
	N      = 1e5 + 7
)

var (
	tc, n, m, fl int
)

func main() {
	// Read the number of test cases, and two integers n and m
	fmt.Scan(&tc, &n, &m)

	// Ensure n is the smaller of the two integers
	if n > m {
		n, m = m, n
	}

	// Loop through the range from 1 to m
	for i := 1; i <= m; i++ {
		// Check if the current value multiplied by tc is within the range [n, m]
		if i*tc >= n && i*tc <= m {
			fmt.Println("OK") // Print "OK" if the condition is satisfied
			fl = 1           // Set the flag to indicate success
			break           // Exit the loop as we found a valid case
		}
	}

	// If no valid case was found, print "NG"
	if fl == 0 {
		fmt.Println("NG")
	}
}

