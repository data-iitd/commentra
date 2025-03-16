package main

import (
	"fmt"
	"sort"
	"strings"
)

func run(s, t string) string {
	ss := countCharacters(s)
	tt := countCharacters(t)

	sort.Ints(ss)
	sort.Ints(tt)

	if equal(ss, tt) {
		return "Yes"
	}
	return "No"
}

func countCharacters(s string) []int {
	counter := make(map[rune]int)
	for _, char := range s {
		counter[char]++
	}

	values := make([]int, 0, len(counter))
	for _, count := range counter {
		values = append(values, count)
	}
	return values
}

func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func main() {
	var s, t string
	fmt.Scan(&s)
	fmt.Scan(&t)
	fmt.Println(run(s, t))
}

// <END-OF-CODE>
