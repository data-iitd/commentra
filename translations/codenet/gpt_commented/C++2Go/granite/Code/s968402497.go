
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the number of test cases, and two integers n and m
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d%d%d\n", &tc, &n, &m)

	// Ensure n is the smaller of the two integers
	if n > m {
		n, m = m, n
	}

	// Loop through the range from 1 to m
	for i := 1; i <= m; i++ {
		// Check if the current value multiplied by tc is within the range [n, m]
		if i*tc >= n && i*tc <= m {
			fmt.Println("OK") // Print "OK" if the condition is satisfied
			return // Exit the function as we found a valid case
		}
	}

	// If no valid case was found, print "NG"
	fmt.Println("NG")
}

