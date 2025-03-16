
package main

import (
	"fmt"
	"sort"
)

func run(s, t string) string {
	// Define the run function that takes two arguments, s and t
	ss := sort.IntSlice(make([]int, 0))
	// Create a slice of ints for ss
	for _, v := range s {
		// Iterate over the characters in s
		ss = append(ss, int(v))
		// Append the character's value to ss
	}
	sort.Sort(ss)
	// Sort ss
	tt := sort.IntSlice(make([]int, 0))
	// Create a slice of ints for tt
	for _, v := range t {
		// Iterate over the characters in t
		tt = append(tt, int(v))
		// Append the character's value to tt
	}
	sort.Sort(tt)
	// Sort tt
	if ss.Equal(tt) {
		// Check if the sorted values of s and t are equal
		return "Yes"
	}
	// If not equal, return "No"
	return "No"
}

func main() {
	// Define the main function to get input and print the result
	var s, t string
	// Declare s and t as strings
	fmt.Scan(&s)
	// Get input for s from the user
	fmt.Scan(&t)
	// Get input for t from the user
	fmt.Println(run(s, t))
	// Call the run function with s and t as arguments and print the result
}

