
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read input values for k (cost per banana), n (initial amount of money), and w (number of bananas)
	k, _ := reader.ReadString(' ')
	n, _ := reader.ReadString('\n')
	w, _ := reader.ReadString('\n')

	// Check if k is at least 1 and w is at most 1000
	if kInt, err := strconv.Atoi(k); err == nil && kInt >= 1 {
		if wInt, err := strconv.Atoi(w); err == nil && wInt <= 1000 {
			// Initialize total cost to zero
			total := 0

			// Calculate the total cost of buying w bananas
			for i := 1; i <= wInt; i++ {
				total += i * kInt // Cost of each banana increases with its quantity (1*k, 2*k,..., w*k)
			}

			// Check if the total cost exceeds the initial amount of money n
			if nInt, err := strconv.Atoi(n); err == nil && total > nInt {
				// Print the amount of money needed to buy the bananas
				fmt.Println(total - nInt)
			} else {
				// Print 0 if the initial amount is sufficient to buy the bananas
				fmt.Println(0)
			}
		}
	}
}
