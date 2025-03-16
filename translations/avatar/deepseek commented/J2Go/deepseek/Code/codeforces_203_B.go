package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	// Initialize a 2D slice 'black' with dimensions (N+2) x (N+2)
	black := make([][]int, N+2)
	for i := range black {
		black[i] = make([]int, N+2)
	}

	// Loop through M operations
	for m := 1; m <= M; m++ {
		var x, y int
		fmt.Scan(&x, &y)

		// Increment the elements in the 'black' slice within the 3x3 neighborhood of (x, y)
		for xx := x - 1; xx <= x+1; xx++ {
			for yy := y - 1; yy <= y+1; yy++ {
				black[xx][yy]++
				if black[xx][yy] == 9 {
					fmt.Println(m)
					return
				}
			}
		}
	}

	// If no element reaches 9 after all operations, print -1
	fmt.Println("-1")
}

