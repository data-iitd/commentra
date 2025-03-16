package main

import (
	"fmt"
)

func main() {
	m := make(map[int]int)

	for i := 0; i*200 < 5001; i++ { // Loop through possible values of i
		for j := 0; j*300 < 5001; j++ { // Loop through possible values of j
			for k := 0; k*500 < 5001; k++ { // Loop through possible values of k
				w := i*200 + j*300 + k*500 // Calculate the weight
				p := (i/5)*5*380*0.8 + (i%5)*380 + // Calculate the price for i
					(j/4)*4*550*0.85 + (j%4)*550 + // Calculate the price for j
					(k/3)*3*850*0.88 + (k%3)*850 // Calculate the price for k

				if val, exists := m[w]; exists {
					if p < val {
						m[w] = p // Update the map with the minimum price
					}
				} else {
					m[w] = p // Add new weight and price to the map
				}
			}
		}
	}

	var n int
	for {
		if _, err := fmt.Scan(&n); err != nil || n == 0 { // Read input until a zero is entered
			break
		}
		fmt.Println(m[n]) // Output the minimum price for the given weight
	}
}

// <END-OF-CODE>
