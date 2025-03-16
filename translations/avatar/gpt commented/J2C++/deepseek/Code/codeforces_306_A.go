package main

import (
	"fmt"
)

func main() {
	// Read two integers n and m from user input
	var n, m int
	fmt.Scan(&n, &m)
	
	// Initialize an array of size m to hold the results
	a := make([]int, m)
	
	// Check if n is divisible by m
	if n % m == 0 {
		// If divisible, fill the array with equal parts
		for i := 0; i < len(a); i++ {
			a[i] = n / m
		}
	} else {
		// If not divisible, calculate the base value for each part
		base := n / m
		for i := 0; i < len(a); i++ {
			a[i] = base
		}
		
		// Calculate the remainder that needs to be distributed
		remainder := n - (base * m)
		count := 0
		
		// Distribute the remainder across the first few elements of the array
		for i := 0; i < remainder; i++ {
			a[count] = a[count] + 1
			count++
			
			// Wrap around if count exceeds the array length
			if count >= len(a) {
				count = 0
			}
		}
	}
	
	// Print the array in reverse order
	for i := len(a) - 1; i >= 0; i-- {
		fmt.Print(a[i], " ")
	}
}

