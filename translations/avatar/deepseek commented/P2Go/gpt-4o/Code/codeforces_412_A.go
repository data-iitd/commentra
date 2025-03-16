package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	// Input the number of elements (n) and the position index (k)

	var v string
	fmt.Scan(&v)
	// Input the string v

	d := []string{"LEFT", "RIGHT"}
	// Define a slice containing the directions "LEFT" and "RIGHT"

	f := (k-1) < (n-k)
	// Determine the boolean value of f based on the comparison between k-1 and n-k

	m := min(k-1, n-k)
	// Assign m as the minimum of k-1 and n-k

	var a []string
	// Initialize an empty slice a to store the sequence of actions

	for i := 0; i < m; i++ {
		a = append(a, d[boolToInt(!f)])
		// Append the opposite direction to a based on the value of f
	}

	step := 1
	if f {
		step = -1
	}
	for i := len(v) - 1; i >= 0; i += step {
		a = append(a, "PRINT "+string(v[i]))
		a = append(a, d[boolToInt(f)])
		// Iterate over the reversed string v with a step of 2*f-1, appending "PRINT" and the current character, followed by the direction f
	}

	fmt.Println(strings.Join(a[:len(a)-1], "\n"))
	// Print all elements in a except the last one, separated by newlines
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

// <END-OF-CODE>
