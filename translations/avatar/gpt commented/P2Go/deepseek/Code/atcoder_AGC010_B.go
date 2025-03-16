package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	var a []int

	// Read the number of elements and the list of integers from input
	fmt.Scan(&n)
	fmt.Scan(&a)

	// Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
	if sum(a) % (n * (n + 1) / 2) != 0 {
		// If not divisible, print "NO" and exit
		fmt.Println("NO")
		return
	}

	// Calculate the average value 'k' that each element should contribute
	k := float64(sum(a)) / float64(n * (n + 1) / 2)
	
	// Append the first element of 'a' to the end of the list to facilitate circular calculations
	a = append(a, a[0])
	
	// Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
	allNonNegative := true
	sumAdjusted := 0
	for i := 1; i < len(a); i++ {
		adjusted := (k - float64(a[i-1]) + float64(a[i])) % float64(n)
		if adjusted < 0 {
			allNonNegative = false
		}
		sumAdjusted += int(adjusted)
	}

	if sumAdjusted != 0 || !allNonNegative {
		// If either condition fails, print "NO"
		fmt.Println("NO")
	} else {
		// If both conditions are satisfied, print "YES"
		fmt.Println("YES")
	}
}

// Helper function to calculate the sum of elements in a list
func sum(a []int) int {
	total := 0
	for _, v := range a {
		total += v
	}
	return total
}
