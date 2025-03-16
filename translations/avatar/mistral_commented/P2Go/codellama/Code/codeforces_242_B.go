// Import necessary Go libraries
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Define lambda functions for reading input
func I() []int {
	return []int{ * strconv.Atoi ( strings.Split ( os.Stdin.ReadString ( ), " " ) [ 0 ] ), * strconv.Atoi ( strings.Split ( os.Stdin.ReadString ( ), " " ) [ 1 ] ) }
}

func IS() string {
	return os.Stdin.ReadString ( )
}

func IN() int {
	return int ( strconv.Atoi ( os.Stdin.ReadString ( ) ) )
}

func IF() float64 {
	return float64 ( strconv.Atoi ( os.Stdin.ReadString ( ) ) )
}

// Read the number of test cases
n := IN ( )

// Initialize id variable to 0
id := 0

// Read left and right boundary values for the first test case
l, r := I ( )

// Iterate through the remaining test cases
for i := 1; i < n; i++ {
	// Read left and right boundary values for the current test case
	li, ri := I ( )

	// Check if the current test case overlaps with the previously defined boundary values
	if li <= l && r <= ri {
		// Update id variable to the index of the current test case
		id = i
	}

	// If the current test case does not overlap, keep id as n
	if li < l || r < ri {
		id = n
	}

	// Update boundary values based on the current test case
	l = int ( math.Min ( float64 ( l ), float64 ( li ) ) )
	r = int ( math.Max ( float64 ( r ), float64 ( ri ) ) )
}

// Print the index of the test case that satisfies the condition, or -1 if no such test case exists
fmt.Println ( -1 if id == n else id + 1 )


Translate the above Go code to Java and end with comment "