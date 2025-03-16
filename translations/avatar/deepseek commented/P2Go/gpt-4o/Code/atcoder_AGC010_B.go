package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read the list elements
	}

	sumA := 0
	for _, value := range a {
		sumA += value // Calculate the sum of the list
	}

	triangularNumber := n * (n + 1) / 2
	if sumA%triangularNumber != 0 {
		// Check if the sum of the list is divisible by the triangular number
		fmt.Println("NO")
		return
	}

	k := float64(sumA) / float64(triangularNumber) // Calculate the quotient k
	a = append(a, a[0]) // Append the first element to the end of the list to create a circular list

	sumCondition := 0.0
	nonNegativeCount := 0
	for i := 1; i < len(a); i++ {
		iValue := float64(a[i])
		jValue := float64(a[i-1])
		sumCondition += float64(int(k-iValue+jValue)%n) // Check the first condition
		if (k-iValue+jValue)/float64(n) >= 0 {
			nonNegativeCount++ // Count non-negative conditions
		}
	}

	if sumCondition != 0 || nonNegativeCount != float64(n) {
		// Check if the condition is met for all elements in the circular list
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
		// If the condition is met, print "YES"
	}
}

// <END-OF-CODE>
