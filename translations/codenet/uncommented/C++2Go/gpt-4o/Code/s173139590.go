package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	acCount := 0
	waCount := 0
	tleCount := 0
	reCount := 0

	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		switch s {
		case "AC":
			acCount++
		case "WA":
			waCount++
		case "TLE":
			tleCount++
		case "RE":
			reCount++
		}
	}

	fmt.Printf("AC x %d\n", acCount)
	fmt.Printf("WA x %d\n", waCount)
	fmt.Printf("TLE x %d\n", tleCount)
	fmt.Printf("RE x %d\n", reCount)
}

// <END-OF-CODE>
