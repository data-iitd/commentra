
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Define the number of strings n and the number of operations m
	var n, m int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &m)

	// Calculate the number of '-' symbols in the input string
	sa := 0
	for {
		ch, _, err := bufio.NewReader(os.Stdin).ReadByte()
		if err!= nil {
			break
		}
		if ch == '-' {
			sa++
		}
	}

	// Ensure the number of '-' symbols is valid
	sa = int(min(int64(n-sa), int64(sa)))

	// Initialize an empty list'ss' to store the results of each operation
	ss := make([]string, 0, m)

	// Perform each operation as described in the problem statement
	for i := 0; i < m; i++ {
		// Read two integers a and b from the input
		var a, b int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &a, &b)

		// Calculate the difference between b and a
		b -= a

		// Check if the difference is valid based on the number of '-' symbols
		if (b%2 == 0 || b > sa<<1) {
			// If the difference is valid, add '1' to the result list'ss'
			ss = append(ss, "1\n")
		} else {
			// If the difference is not valid, add '0' to the result list'ss'
			ss = append(ss, "0\n")
		}
	}

	// Print the final result by joining all the strings in the'ss' list with an empty string as separator
	fmt.Print(strings.Join(ss, ""))
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

