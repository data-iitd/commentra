package main

import (
	"fmt"
	"sort"
)

func run(s, t string) string {
	// Count the frequency of each character in string s and sort the frequencies
	ss := make([]int, 26)
	for _, v := range s {
		ss[v-'a']++
	}
	sort.Ints(ss)

	// Count the frequency of each character in string t and sort the frequencies
	tt := make([]int, 26)
	for _, v := range t {
		tt[v-'a']++
	}
	sort.Ints(tt)

	// Compare the sorted frequency lists of both strings
	if ss == tt {
		return "Yes" // Return 'Yes' if the frequency distributions are the same
	}
	return "No"    // Return 'No' if the frequency distributions are different
}

func main() {
	// Read input strings s and t from the user
	var s, t string
	fmt.Scanf("%s %s", &s, &t)

	// Print the result of the run function which checks the character frequency
	fmt.Println(run(s, t))
}

