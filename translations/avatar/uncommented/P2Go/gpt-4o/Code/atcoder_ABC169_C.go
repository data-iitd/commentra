package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set a high recursion limit (not directly applicable in Go)
	// In Go, we don't have a direct equivalent to setrecursionlimit

	// Debugging function
	dbg := func(args ...interface{}) {
		if _, ok := os.LookupEnv("TERM_PROGRAM"); ok {
			fmt.Println(args...)
		}
	}

	// Input reading
	var sa, sb string
	fmt.Scan(&sa, &sb)

	a, _ := strconv.Atoi(sa)
	bFloat, _ := strconv.ParseFloat(sb, 64)
	b := int(math.Round(bFloat * 100))

	// Calculate and print the result
	fmt.Println(a * b / 100)
}

// <END-OF-CODE>
