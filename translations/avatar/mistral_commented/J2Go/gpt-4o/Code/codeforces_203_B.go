package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N) // Read the first integer from the input, which represents the size of the grid
	fmt.Scan(&M) // Read the second integer from the input, which represents the number of stones to be placed on the grid

	black := make([][]int, N+2) // Create a 2D slice of size (N+2) x (N+2) to represent the grid
	for i := range black {
		black[i] = make([]int, N+2)
	}

	for m := 1; m <= M; m++ { // Iterate M times, once for each stone to be placed
		var x, y int
		fmt.Scan(&x) // Read the x-coordinate of the next stone to be placed
		fmt.Scan(&y) // Read the y-coordinate of the next stone to be placed

		for xx := x - 1; xx <= x+1; xx++ { // Iterate over all the neighboring cells in the x-direction
			for yy := y - 1; yy <= y+1; yy++ { // Iterate over all the neighboring cells in the y-direction
				if black[xx][yy]++; black[xx][yy] == 9 { // Check if the number of black cells around this cell becomes 9
					fmt.Println(m) // If so, print the index of the stone that caused this condition and return
					return
				}
			}
		}
	}

	fmt.Println("-1") // If we finish iterating over all the stones without finding one that has 9 black neighbors, print -1 and return
}

// <END-OF-CODE>
