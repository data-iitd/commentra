package main

import (
	"fmt"
)

func main() {
	var a, c, k, b int // Declare variables to store input, counters, and temporary values

	// Start a while loop to read input
	for {
		_, err := fmt.Scan(&a) // Read an integer 'a' from the input
		if err != nil {
			break
		}
		c = 0
		k = 0

		if a < 3 {
			fmt.Println(0)
		} else {
			b = a
			for a > 0 {
				b--
				c++
				if c == 3 {
					k++
					c = 0
				}
				a--
			}
			fmt.Println(k)
		}
	}
}

