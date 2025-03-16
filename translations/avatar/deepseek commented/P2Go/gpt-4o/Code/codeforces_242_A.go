package main

import (
	"fmt"
)

func main() {
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)
	// Taking input values for x, y, a, and b

	games := []struct{ i, j int }{}
	// Initializing an empty slice of structs to hold pairs (i, j)

	for i := a; i <= x; i++ {
		// Looping from a to x
		if i <= b {
			continue
		}
		// Skipping values of i that are less than or equal to b
		for j := b; j <= y; j++ {
			// Looping from b to y
			if i > j {
				// Checking if i is greater than j
				games = append(games, struct{ i, j int }{i, j})
				// Appending the struct (i, j) to the games slice
			}
		}
	}

	fmt.Println(len(games))
	// Printing the length of the games slice
	for _, game := range games {
		fmt.Printf("%d %d\n", game.i, game.j)
		// Printing each struct in the games slice
	}
}

// <END-OF-CODE>
