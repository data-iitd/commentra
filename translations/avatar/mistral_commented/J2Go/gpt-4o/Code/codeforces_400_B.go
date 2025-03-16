package main

import (
	"fmt"
	"strings"
)

func main() {
	// Initializing variables for reading input
	var n, m int
	fmt.Scan(&n, &m) // Reading the first two integers from the input

	// Creating a slice of strings to store input strings
	arrs := make([]string, n)

	// Iterating through the slice and storing each string
	for i := 0; i < n; i++ {
		fmt.Scan(&arrs[i]) // Reading a string from the input
	}

	// Initializing a slice to store the length of substrings between "G" and "S"
	length := make([]int, n)
	index := 0 // Index for storing the current index in the length slice
	returnDex := -1 // Index for storing the index of the string with "G" before "S"

	// Iterating through each string in the slice and finding the length of substrings between "G" and "S"
	for i, tmp := range arrs {
		dexG := strings.Index(tmp, "G") // Finding the index of "G" in the current string
		dexS := strings.Index(tmp, "S") // Finding the index of "S" in the current string

		// Checking if "G" comes before "S" in the current string
		if dexG > dexS {
			returnDex = i // Storing the index of the string with "G" before "S"
			break // Exiting the loop as we have found the required string
		}

		// Storing the length of the substring between "G" and "S" in the length slice
		if dexG != -1 && dexS != -1 {
			length[index] = dexS - dexG
			index++
		}
	}

	// Creating a map to store the unique lengths of substrings
	set := make(map[int]struct{})

	// Iterating through the length slice and adding each unique length to the map
	for i := 0; i < index; i++ {
		set[length[i]] = struct{}{}
	}

	// Checking if there is a string with "G" before "S"
	if returnDex == -1 {
		// Printing the result if there is no such string
		fmt.Println(returnDex)
	} else {
		// Printing the size of the map if there is a string with "G" before "S"
		fmt.Println(len(set))
	}
}

// <END-OF-CODE>
