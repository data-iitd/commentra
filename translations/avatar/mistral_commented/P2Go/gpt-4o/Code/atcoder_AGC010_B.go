package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Check if the sum of the elements in the list is divisible by the formula
	sumA := 0
	for _, value := range a {
		sumA += value
	}

	if sumA%(n*(n+1)/2) != 0 {
		fmt.Println("NO")
		return
	}

	// Calculate the average of the elements in the list
	k := float64(sumA) / float64(n*(n+1)/2)

	// Add the first element to the end of the list for simplification
	a = append(a, a[0])

	// Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
	valid := true
	for i := 1; i < len(a); i++ {
		if int(k)-a[i]+a[i-1] < 0 || (int(k)-a[i]+a[i-1])%n != 0 {
			valid = false
			break
		}
	}

	if !valid {
		fmt.Println("NO")
		return
	}

	// If all checks pass, print YES
	fmt.Println("YES")
}

// <END-OF-CODE>
