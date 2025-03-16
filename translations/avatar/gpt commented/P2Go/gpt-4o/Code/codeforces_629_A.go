package main

import (
	"fmt"
)

func main() {
	// Read the number of lines (n) from user input
	var n int
	fmt.Scan(&n)

	// Initialize a slice to store the cake representation and variables for happiness and chocolate count
	cake := make([]string, n)
	happiness := 0.0
	chocCount := 0
	nfat := 1

	// Process each line of cake input
	for i := 0; i < n; i++ {
		// Read a line of cake representation
		var line string
		fmt.Scan(&line)
		// Append the line to the cake slice
		cake[i] = line

		// Count the number of chocolates ('C') in the current line
		for _, j := range line {
			if j == 'C' {
				chocCount++
			}
		}

		// If there are more than one chocolate, calculate the happiness contribution
		if chocCount > 1 {
			// Calculate the factorial of (chocCount - 1) and (chocCount - 2)
			for k := chocCount; k > chocCount-2; k-- {
				nfat *= k
			}
			// Update happiness based on the calculated factorial
			happiness += float64(nfat) / 2
		}

		// Reset variables for the next line
		nfat = 1
		chocCount = 0
	}

	// Initialize a counter for vertical chocolate counting
	chocCount = 0

	// Count chocolates in each column of the cake
	for j := 0; j < n; j++ {
		for i := 0; i < n; i++ {
			// Count the number of chocolates ('C') in the current column
			if cake[i][j] == 'C' {
				chocCount++
			}
		}

		// If there are more than one chocolate in the column, calculate the happiness contribution
		if chocCount > 1 {
			// Calculate the factorial of (chocCount - 1) and (chocCount - 2)
			for k := chocCount; k > chocCount-2; k-- {
				nfat *= k
			}
			// Update happiness based on the calculated factorial
			happiness += float64(nfat) / 2
		}

		// Reset variables for the next column
		nfat = 1
		chocCount = 0
	}

	// Print the total happiness as an integer
	fmt.Println(int(happiness))
}

// <END-OF-CODE>
