
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Declare a map to store the minimum price for each weight
	m := make(map[int]int)

	// Iterate over possible quantities of items weighing 200 units
	for i := 0; i*200 < 50001; i++ {
		// Iterate over possible quantities of items weighing 300 units
		for j := 0; j*300 < 50001; j++ {
			// Iterate over possible quantities of items weighing 500 units
			for k := 0; k*500 < 50001; k++ {
				// Calculate the total weight based on the quantities of items
				w := i*200 + j*300 + k*500

				// Calculate the price based on the quantities of items
				p := i/5*5*380*0.8 + i%5*380 +
					j/4*4*550*0.85 + j%4*550 +
					k/3*3*850*0.88 + k%3*850

				// Update the map with the minimum price for the calculated weight
				if m[w] == 0 {
					m[w] = p
				} else if m[w] > p {
					m[w] = p
				}
			}
		}
	}

	// Read input weights and output the corresponding minimum prices
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		n, _ := fmt.Sscanf(scanner.Text(), "%d", &n)
		if n == 0 {
			break
		}
		fmt.Println(m[n]) // Output the minimum price for the given weight
	}
}
