package main

import (
	"fmt"
	"os"
)

func main() {
	// Taking input for number of test cases and time limit
	var n, t int
	fmt.Scan(&n, &t)

	// Initializing a slice to store the jumps
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Initializing the current cell position to 0
	currentCell := 0

	// Main logic of the program starts here
	for currentCell < t {
		// Incrementing the current cell position by the jump from the previous cell
		currentCell += s[currentCell]

		// Checking if the current cell position is equal to the target position
		if currentCell == t {
			// If yes, then print "YES" and exit the program
			fmt.Println("YES")
			os.Exit(0)
		}
	}

	// If the loop terminates without finding the target position, then print "NO"
	fmt.Println("NO")
}

// <END-OF-CODE>
