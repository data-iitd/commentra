
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var x, y, a, b int
	var count int

	// Read input
	fmt.Scan(&x, &y, &a, &b)

	// Nested loops to iterate through possible pairs (i, j)
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			if i <= j {
				continue
			}
			count++
		}
	}

	fmt.Println(count)

	// Print each valid pair
	for i := a; i <= x; i++ {
		for j := b; j <= y; j++ {
			if i <= j {
				continue
			}
			fmt.Println(i, j)
		}
	}
}

