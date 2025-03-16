package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Define long long type for large integers
type ll int64

// Constants for infinity and modulo operations
const inf int = math.MaxInt32
const mod int = (1? 1e9 + 7 : 998244353)

func main() {
	// Optimize input/output operations
	defer fmt.Fprintln(os.Stderr, "end of code")
	defer os.Exit(0)

	// Declare variables for input and processing
	var a, b, c, d, e, f, g, T ll
	var z string

	// Read the input string
	fmt.Scanf("%s", &z)

	// Get the size of the input string
	a = ll(len(z))

	// Check for consecutive identical characters in the string
	for i := 0; i < a - 1; i++ {
		// If two consecutive characters are the same, print "Bad" and exit
		if z[i] == z[i + 1] {
			fmt.Println("Bad")
			return
		}
	}

	// If no consecutive identical characters were found, print "Good"
	fmt.Println("Good")
}

