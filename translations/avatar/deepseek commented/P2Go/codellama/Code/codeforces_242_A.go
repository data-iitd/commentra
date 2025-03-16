
package main

import "fmt"

func main() {
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)
	// Taking input values for x, y, a, and b
	games := make([][2]int, 0)
	// Initializing an empty slice called games
	for i := a; i <= x; i++ {
		// Looping from a to x
		if i <= b {
			continue
			// Skipping values of i that are less than or equal to b
		} else {
			for j := b; j <= y; j++ {
				// Looping from b to y
				if i > j {
					// Checking if i is greater than j
					games = append(games, [2]int{i, j})
					// Appending the tuple (i, j) to the games slice
				}
			}
		}
	}
	fmt.Println(len(games))
	// Printing the length of the games slice
	for _, i := range games {
		fmt.Printf("%d %d\n", i[0], i[1])
		// Printing each tuple in the games slice
	}
}

