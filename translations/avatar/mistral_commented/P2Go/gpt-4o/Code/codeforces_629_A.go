package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of lines in the input
	cake := make([]string, n) // Initialize a slice to store each line
	happiness := 0.0           // Initialize happiness variable to zero
	chocCount := 0             // Initialize chocolate count variable to zero
	nfat := 1                   // Initialize nFAT variable to 1

	for i := 0; i < n; i++ { // Iterate through each line in the input
		var line string
		fmt.Scan(&line) // Read a line
		cake[i] = line   // Store the line in the slice

		for _, j := range line { // Iterate through each character in the line
			if j == 'C' { // If the character is 'C', increment chocolate count
				chocCount++
			}
		}

		if chocCount > 1 { // If there are more than one 'C' in the line
			nfat = 1 // Reset nFAT to 1
			for k := chocCount; k > chocCount-2; k-- { // Calculate nFAT using the chocolate count
				nfat *= k
			}
			happiness += nfat / 2 // Add happiness based on the nFAT value
		}

		chocCount = 0 // Reset chocolate count to zero
	}

	posCount := 0 // Initialize position count variable to zero
	for j := 0; j < n; j++ { // Iterate through each column in the cake
		for i := 0; i < n; i++ { // Iterate through each line in the cake
			if cake[i][j] == 'C' { // If the character at the position (i,j) is 'C', increment chocolate count
				chocCount++
			}
		}

		if chocCount > 1 { // If there are more than one 'C' in the column
			nfat = 1 // Reset nFAT to 1
			for k := chocCount; k > chocCount-2; k-- { // Calculate nFAT using the chocolate count
				nfat *= k
			}
			happiness += nfat / 2 // Add happiness based on the nFAT value
		}

		chocCount = 0 // Reset chocolate count to zero
	}

	fmt.Println(int(happiness)) // Print the final happiness value as an integer.
}

// <END-OF-CODE>
