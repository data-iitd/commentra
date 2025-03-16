
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of contest results from the standard input
	n, _ := strconv.Atoi(os.Args[1])

	// Initialize variables to store the number of each contest result
	ac_count := 0
	wa_count := 0
	tle_count := 0
	re_count := 0

	// Read each contest result and update the corresponding counter
	for i := 0; i < n; i++ {
		s := os.Args[i+2]
		if s == "AC" {
			ac_count++
		} else if s == "WA" {
			wa_count++
		} else if s == "TLE" {
			tle_count++
		} else if s == "RE" {
			re_count++
		}
	}

	// Print the number of each contest result to the standard output
	fmt.Printf("AC x %d\n", ac_count)
	fmt.Printf("WA x %d\n", wa_count)
	fmt.Printf("TLE x %d\n", tle_count)
	fmt.Printf("RE x %d\n", re_count)
}

