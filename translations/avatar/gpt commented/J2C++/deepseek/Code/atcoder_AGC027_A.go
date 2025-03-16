package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a Scanner object to read input from the console
	var N int
	var x int64
	fmt.Scan(&N, &x)
	
	// Initialize a slice to store the sweetness values of the items
	sweet := make([]int64, N)
	
	// Read the sweetness values and add them to the slice
	for i := 0; i < N; i++ {
		fmt.Scan(&sweet[i])
	}
	
	// Sort the slice of sweetness values in ascending order
	sort.Slice(sweet, func(i, j int) bool {
		return sweet[i] < sweet[j]
	})
	
	// Initialize a counter for the number of sweet items that can be bought
	num := 0
	
	// Iterate through the sorted sweetness values
	for i := 0; i < N; i++ {
		// Check if the current sweetness value can be bought with the remaining money
		if x - sweet[num] >= 0 {
			// Deduct the sweetness value from the total money
			x = x - sweet[num]
			// Increment the count of items bought
			num++
		} else {
			// If the current item cannot be bought, exit the loop
			break
		}
	}
	
	// Adjust the count if all items were bought but there is still money left
	if num == N && x > 0 {
		num -= 1
	}
	
	// Print the total number of sweet items that can be bought
	fmt.Println(num)
}

