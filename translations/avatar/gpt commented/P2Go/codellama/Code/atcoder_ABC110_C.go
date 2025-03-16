
package main

import (
	"fmt"
	"sort"
)

func run(s, t string) string {
	// Count the frequency of each character in string s and sort the frequencies
	ss := sortFrequency(s)

	// Count the frequency of each character in string t and sort the frequencies
	tt := sortFrequency(t)

	// Compare the sorted frequency lists of both strings
	if ss == tt {
		return "Yes" // Return 'Yes' if the frequency distributions are the same
	} else {
		return "No" // Return 'No' if the frequency distributions are different
	}
}

func sortFrequency(s string) []int {
	// Count the frequency of each character in string s
	freq := make(map[rune]int)
	for _, r := range s {
		freq[r]++
	}

	// Sort the frequencies
	ss := make([]int, 0, len(freq))
	for _, v := range freq {
		ss = append(ss, v)
	}
	sort.Ints(ss)

	return ss
}

func main() {
	// Read input strings s and t from the user
	var s, t string
	fmt.Scan(&s, &t)

	// Print the result of the run function which checks the character frequency
	fmt.Println(run(s, t))
}

