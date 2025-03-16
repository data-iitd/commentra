package main

import (
	"fmt"
	"sort"
)

func run(s, t string) string {
	// Count the frequency of each character in string s and sort the frequencies
	ss := make([]int, 0, len(s))
	count := make(map[rune]int)
	for _, char := range s {
		count[char]++
	}
	for _, value := range count {
		ss = append(ss, value)
	}
	sort.Ints(ss)
	
	// Count the frequency of each character in string t and sort the frequencies
	tt := make([]int, 0, len(t))
	count = make(map[rune]int)
	for _, char := range t {
		count[char]++
	}
	for _, value := range count {
		tt = append(tt, value)
	}
	sort.Ints(tt)
	
	// Compare the sorted frequency lists of both strings
	if len(ss) != len(tt) {
		return "No"
	}
	for i := range ss {
		if ss[i] != tt[i] {
			return "No"
		}
	}
	return "Yes"
}

func main() {
	// Read input strings s and t from the user
	var s, t string
	fmt.Scan(&s, &t)
	
	// Print the result of the run function which checks the character frequency
	fmt.Println(run(s, t))
}

