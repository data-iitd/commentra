package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Take the size of the cake as input
	cake := make([]string, n) // Initialize a slice to store the rows of the cake
	happiness := 0.0 // Initialize the happiness score to 0
	chocCount := 0 // Initialize the chocolate count to 0
	nfat := 1 // Initialize nfat to 1 for calculating factorial

	// Loop through each row of the cake
	for i := 0; i < n; i++ {
		var line string
		fmt.Scan(&line) // Take each row as input
		cake[i] = line // Append the row to the cake slice
		for _, j := range line { // Loop through each character in the row
			if j == 'C' { // If the character is a chocolate
				chocCount++ // Increment the chocolate count
			}
		}
		if chocCount > 1 { // If there is more than one chocolate in the row
			// Calculate the factorial of chocCount and update happiness
			for k := chocCount; k > chocCount-2; k-- {
				nfat *= k
			}
			happiness += float64(nfat) / 2
		}
		nfat = 1 // Reset nfat to 1
		chocCount = 0 // Reset chocCount to 0
	}

	// Loop through each column of the cake
	for j := 0; j < n; j++ {
		chocCount = 0 // Reset the chocolate count for each column
		for i := 0; i < n; i++ {
			if cake[i][j] == 'C' { // If the character is a chocolate
				chocCount++ // Increment the chocolate count
			}
		}
		if chocCount > 1 { // If there is more than one chocolate in the column
			// Calculate the factorial of chocCount and update happiness
			for k := chocCount; k > chocCount-2; k-- {
				nfat *= k
			}
			happiness += float64(nfat) / 2
		}
		nfat = 1 // Reset nfat to 1
		chocCount = 0 // Reset chocCount to 0
	}

	fmt.Println(int(happiness)) // Print the integer value of happiness
}

// <END-OF-CODE>
