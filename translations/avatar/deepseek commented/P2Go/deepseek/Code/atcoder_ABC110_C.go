package main

import (
	"fmt"
	"sort"
)

func run(s, t string) string {
	// Define the run function that takes two arguments, s and t
	ss := make(map[rune]int)
	// Create a map to count the frequency of each character in s
	for _, char := range s {
		ss[char]++
	}
	// Count the frequency of each character in s
	tt := make(map[rune]int)
	// Create a map to count the frequency of each character in t
	for _, char := range t {
		tt[char]++
	}
	// Count the frequency of each character in t
	var valuesS, valuesT []int
	// Create slices to store the frequency values of s and t
	for _, value := range ss {
		valuesS = append(valuesS, value)
	}
	for _, value := range tt {
		valuesT = append(valuesT, value)
	}
	// Convert the frequency maps to slices of values
	sort.Ints(valuesS)
	// Sort the values of s
	sort.Ints(valuesT)
	// Sort the values of t
	if string(valuesS) == string(valuesT) {
		// Check if the sorted values of s and t are equal
		return "Yes"
	} else {
		// If not equal, return "No"
		return "No"
	}
}

func main() {
	// Define the main function to get input and print the result
	var s, t string
	// Declare variables to store input strings
	fmt.Scan(&s)
	// Get input for s from the user
	fmt.Scan(&t)
	// Get input for t from the user
	fmt.Println(run(s, t))
	// Call the run function with s and t as arguments and print the result
}

