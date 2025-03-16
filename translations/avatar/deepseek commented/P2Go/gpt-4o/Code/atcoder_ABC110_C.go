package main

import (
	"fmt"
	"sort"
)

func run(s string, t string) string {
	// Create a map to count occurrences of each character in s
	countS := make(map[rune]int)
	for _, char := range s {
		countS[char]++
	}

	// Create a slice to hold the counts and sort it
	countSliceS := make([]int, 0, len(countS))
	for _, count := range countS {
		countSliceS = append(countSliceS, count)
	}
	sort.Ints(countSliceS)

	// Create a map to count occurrences of each character in t
	countT := make(map[rune]int)
	for _, char := range t {
		countT[char]++
	}

	// Create a slice to hold the counts and sort it
	countSliceT := make([]int, 0, len(countT))
	for _, count := range countT {
		countSliceT = append(countSliceT, count)
	}
	sort.Ints(countSliceT)

	// Compare the sorted slices
	if len(countSliceS) != len(countSliceT) {
		return "No"
	}
	for i := range countSliceS {
		if countSliceS[i] != countSliceT[i] {
			return "No"
		}
	}
	return "Yes"
}

func main() {
	var s, t string
	fmt.Scanln(&s) // Get input for s from the user
	fmt.Scanln(&t) // Get input for t from the user
	fmt.Println(run(s, t)) // Call the run function with s and t as arguments and print the result
}

// <END-OF-CODE>
