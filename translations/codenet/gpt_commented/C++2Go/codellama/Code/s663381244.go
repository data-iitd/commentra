package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Disable synchronization with C I/O for faster input/output
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	// Initialize a vector to hold the denominations of money
	m := []int{10, 50, 100, 500}

	// Read money input until EOF or invalid input
	for {
		// Read a line of input
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Scan()
		line := scanner.Text()

		// Check if the input is valid
		if line == "" {
			break
		}

		// Convert the input to an integer
		money, err := strconv.Atoi(line)
		if err != nil {
			fmt.Println("Invalid input")
			continue
		}

		// Print a newline before the output of subsequent transactions
		if money > 0 {
			fmt.Println()
		}

		sum := 0 // Initialize sum to calculate total value of coins
		num := make([]int, 4) // Vector to hold the number of each denomination

		// Read the number of coins for each denomination and calculate the total sum
		for i := 0; i < 4; i++ {
			scanner.Scan()
			line := scanner.Text()
			num[i], err = strconv.Atoi(line)
			if err != nil {
				fmt.Println("Invalid input")
				continue
			}
			sum += num[i] * m[i]
		}

		// Calculate the change to be returned
		change := sum - money

		// Calculate how many coins of each denomination to return as change
		for i := 3; i >= 0; i-- {
			if change/m[i] > 0 { // Check if the current denomination can be used for change
				num[i] = num[i] - change/m[i]
				change %= m[i]
			}
		}

		// Output the remaining coins of each denomination that are greater than zero
		for i := 0; i < 4; i++ {
			if num[i] > 0 { // Only print denominations that still have coins left
				fmt.Println(m[i], num[i])
			}
		}
	}
}

