package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Set the recursion limit (not applicable in Go as it has a different recursion model)
	
	// Debugging function to print debug information if TERM_PROGRAM is set
	dbg := func(args ...interface{}) {
		if _, ok := os.LookupEnv("TERM_PROGRAM"); ok {
			fmt.Println(args...)
		}
	}

	// Read input from stdin without trailing whitespace
	var sa, sb string
	fmt.Scan(&sa, &sb)

	// Convert inputs to integers
	a, _ := strconv.Atoi(sa)
	bFloat, _ := strconv.ParseFloat(sb, 64)
	b := int(bFloat*100 + 0.1)

	// Perform the calculation and print the result
	fmt.Println(a * b / 100)
}

// <END-OF-CODE>
