package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from the input
	ara := make([]int, n) // Creating an integer slice of size n
	frequencyMap := make(map[int]int) // Creating an empty map to store the frequency of each integer

	// Reading elements of the array and updating the frequency in the map
	for i := 0; i < n; i++ {
		var v int
		fmt.Scan(&v) // Reading an integer from the input
		ara[i] = v // Storing the integer in the slice
		frequencyMap[v]++ // Incrementing the frequency of the integer
	}

	// Finding the maximum frequency in the map
	max := 0
	for _, freq := range frequencyMap {
		if freq > max {
			max = freq // Updating max with the maximum frequency found so far
		}
	}

	// Finding the element(s) with the maximum frequency
	elementMap := make(map[int]int) // Creating an empty map to store the elements and their frequencies
	for i := 0; i < n; i++ {
		if _, exists := elementMap[ara[i]]; !exists { // Checking if the current element is already present in the map
			elementMap[ara[i]] = 1 // If not, add it with a frequency of 1
			if elementMap[ara[i]] == max { // Checking if the frequency of the current element is equal to the maximum frequency
				fmt.Println(ara[i]) // If yes, print it and break out of the loop
				break
			}
		} else {
			elementMap[ara[i]]++ // If the current element is already present, increment its frequency by 1
			if elementMap[ara[i]] == max { // Checking if the frequency of the current element is equal to the maximum frequency
				fmt.Println(ara[i]) // If yes, print it and break out of the loop
				break
			}
		}
	}
}

// <END-OF-CODE>
