package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	var acCount, waCount, tleCount, reCount int

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		if strings.EqualFold(s, "AC") {
			acCount++
		} else if strings.EqualFold(s, "WA") {
			waCount++
		} else if strings.EqualFold(s, "TLE") {
			tleCount++
		} else if strings.EqualFold(s, "RE") {
			reCount++
		}
	}

	fmt.Printf("AC x %d\n", acCount)
	fmt.Printf("WA x %d\n", waCount)
	fmt.Printf("TLE x %d\n", tleCount)
	fmt.Printf("RE x %d\n", reCount)
}

