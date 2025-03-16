package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scan(&n)

	// Read the list of integers
	var input string
	fmt.Scan(&input)
	strs := strings.Split(input, " ")
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strs[i])
	}

	// Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
	sumA := 0
	for _, value := range a {
		sumA += value
	}
	sumNatural := n * (n + 1) / 2

	if sumA%sumNatural != 0 {
		// If not divisible, print "NO" and exit
		fmt.Println("NO")
		return
	}

	// Calculate the average value 'k' that each element should contribute
	k := float64(sumA) / float64(sumNatural)

	// Append the first element of 'a' to the end of the slice to facilitate circular calculations
	a = append(a, a[0])

	// Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
	adjustedSum := 0
	allNonNegative := true
	for i := 1; i < len(a); i++ {
		adjustedValue := int(k - float64(a[i-1]) + float64(a[i]))
		adjustedSum += adjustedValue
		if adjustedValue < 0 {
			allNonNegative = false
		}
	}

	if adjustedSum != 0 || !allNonNegative {
		// If either condition fails, print "NO"
		fmt.Println("NO")
	} else {
		// If both conditions are satisfied, print "YES"
		fmt.Println("YES")
	}
}

// <END-OF-CODE>
