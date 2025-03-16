package main

import (
	"fmt"
	"sort"
)

// run is a function that takes two strings as arguments and returns a string
func run(s, t string) string {
	// Using sort.Slice function to sort the string's'
	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})

	// Using sort.Slice function to sort the string 't'
	sort.Slice(t, func(i, j int) bool {
		return t[i] < t[j]
	})

	// Comparing the sorted strings's' and 't'
	// If they are equal, then the strings have the same frequency distribution of characters
	// and thus are identical, so return 'Yes'
	// Otherwise, return 'No'
	if s == t {
		return "Yes"
	}
	return "No"
}

// main is a function that takes no arguments
func main() {
	// Taking input strings's' and 't' from the user
	var s, t string
	fmt.Scanln(&s, &t)

	// Calling the 'run' function with strings's' and 't' as arguments and printing the result
	fmt.Println(run(s, t))
}

// 