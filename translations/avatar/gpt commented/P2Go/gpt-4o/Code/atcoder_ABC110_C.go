package main

import (
	"fmt"
	"sort"
)

func run(s, t string) string {
	// Count the frequency of each character in string s
	ss := make(map[rune]int)
	for _, char := range s {
		ss[char]++
	}

	// Count the frequency of each character in string t
	tt := make(map[rune]int)
	for _, char := range t {
		tt[char]++
	}

	// Create slices to hold the frequency values
	freqS := make([]int, 0, len(ss))
	freqT := make([]int, 0, len(tt))

	for _, count := range ss {
		freqS = append(freqS, count)
	}
	for _, count := range tt {
		freqT = append(freqT, count)
	}

	// Sort the frequency slices
	sort.Ints(freqS)
	sort.Ints(freqT)

	// Compare the sorted frequency slices of both strings
	if len(freqS) != len(freqT) {
		return "No"
	}
	for i := range freqS {
		if freqS[i] != freqT[i] {
			return "No"
		}
	}
	return "Yes"
}

func main() {
	var s, t string
	// Read input strings s and t from the user
	fmt.Scanln(&s)
	fmt.Scanln(&t)

	// Print the result of the run function which checks the character frequency
	fmt.Println(run(s, t))
}

// <END-OF-CODE>
