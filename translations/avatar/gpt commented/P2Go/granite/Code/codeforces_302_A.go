
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read two integers n and m from input
	var n, m int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d\n", &n, &m)

	// Count the number of '-' characters in the input string
	sa := 0
	for {
		c, _, err := bufio.NewReader(os.Stdin).ReadRune()
		if err!= nil {
			break
		}
		if c == '-' {
			sa++
		}
	}

	// Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
	sa = int(min(int64(n-sa), int64(sa)))

	// Initialize an empty list to store results
	ss := make([]string, m)

	// Loop m times to read pairs of integers a and b
	for i := 0; i < m; i++ {
		// Read two integers a and b from input
		var a, b int
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d\n", &a, &b)

		// Calculate the difference b - a
		b -= a

		// Check if b is odd and less than or equal to double the count of '-'
		// Append "1\n" to the results if true, otherwise append "0\n"
		if b%2 == 1 && b <= sa*2 {
			ss[i] = "1\n"
		} else {
			ss[i] = "0\n"
		}
	}

	// Print the concatenated results from the list
	fmt.Print(strings.Join(ss, ""))
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

