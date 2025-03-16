
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read an integer n from the user input
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())

	// Print the value of n
	fmt.Println(n)

	// Initialize a variable m with the value of n
	m := n

	// Enter a loop that runs from n-1 down to 1
	for i := n - 1; i > 0; i-- {
		// Check if m is divisible by i
		if m%i == 0 {
			// If m is divisible by i, print i and update m to i
			fmt.Println(i)
			m = i
		}
	}
}

