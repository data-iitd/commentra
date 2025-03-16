package main

import (
	"fmt"
)

func main() {
	var n int
	var array [100]int

	// Step 3: Read the number of elements and the elements of the array.
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&array[i])
	}

	// Step 4: Calculate the sum of the products of all pairs of elements in the array.
	sum := 0
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			sum += array[i] * array[j]
		}
	}

	// Step 5: Print the result.
	fmt.Println(sum)
}

