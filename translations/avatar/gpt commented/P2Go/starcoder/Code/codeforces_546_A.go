package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read k, n, and w
	line, _ := reader.ReadString('\n')
	k, n, w := strings.Fields(line), strings.Fields(line), strings.Fields(line)

	// Check if k is at least 1 and w is at most 1000
	if 1 <= int(k[0]) && int(w[0]) <= 1000 {
		// Initialize total cost to zero
		total := 0

		// Calculate the total cost of buying w bananas
		for i := 1; i <= int(w[0]); i++ {
			total += i * int(k[0]) // Cost of each banana increases with its quantity (1*k, 2*k,..., w*k)

		// Check if the total cost exceeds the initial amount of money n
		if total > int(n[0]) {
			// Print the amount of money needed to buy the bananas
			fmt.Println(total - int(n[0]))
		} else {
			// Print 0 if the initial amount is sufficient to buy the bananas
			fmt.Println(0)
		}
	}
}

