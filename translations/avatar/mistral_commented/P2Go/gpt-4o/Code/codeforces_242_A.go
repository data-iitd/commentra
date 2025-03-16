package main

import (
	"fmt"
)

func main() {
	// Get user input as a string and convert it to a list of integers
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)

	// Initialize an empty slice to store the games
	var games [][2]int

	// Iterate through a range of numbers from a to x+1
	for i := a; i <= x; i++ {
		// If i is less than or equal to b, skip to the next iteration
		if i <= b {
			continue
		}
		// Iterate through a range of numbers from b to y+1
		for j := b; j <= y; j++ {
			// If i is greater than j, append the tuple (i, j) to the games slice
			if i > j {
				games = append(games, [2]int{i, j})
			}
		}
	}

	// Print the length of the games slice
	fmt.Println(len(games))
	// Iterate through the games slice and print each tuple
	for _, game := range games {
		// Print the tuple as a string in the format "i j"
		fmt.Printf("%d %d\n", game[0], game[1])
	}
}

// <END-OF-CODE>
