
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var a, b int
	var c string
	var MfriendPerDay [367]int
	var FfriendPerDay [367]int
	var answer int

	// Read the number of entries
	fmt.Scan(&n)

	// Loop through each entry
	for i := 0; i < n; i++ {
		// Read the gender (M or F)
		fmt.Scan(&c)
		// Read the start day
		fmt.Scan(&a)
		// Read the end day
		fmt.Scan(&b)

		// Update the friend counts for each day in the range
		for j := a; j <= b; j++ {
			if c == "M" {
				MfriendPerDay[j]++
			} else {
				FfriendPerDay[j]++
			}

			// Determine which gender has the lower count and update the answer
			if MfriendPerDay[j] < FfriendPerDay[j] {
				if MfriendPerDay[j] > answer {
					answer = MfriendPerDay[j]
				}
			} else {
				if FfriendPerDay[j] > answer {
					answer = FfriendPerDay[j]
				}
			}
		}
	}

	// Output the result, which is twice the maximum number of friends on any single day
	fmt.Println(answer * 2)
}

