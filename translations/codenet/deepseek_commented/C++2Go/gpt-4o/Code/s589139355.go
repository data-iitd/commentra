package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var a, t, h int
	fmt.Scan(&a)
	var taro, hana string

	// Loop through the number of games
	for i := 0; i < a; i++ {
		// Read the names of Taro and Hana
		fmt.Scan(&taro, &hana)

		// Initialize score counters for this round
		tt, hh := 0, 0

		// Compare the names and update the scores
		if taro > hana {
			t += 3
		} else if hana > taro {
			h += 3
		} else if hana == taro {
			h++
			t++
		}
	}

	// Output the final scores
	fmt.Println(t, h)
}

// <END-OF-CODE>
