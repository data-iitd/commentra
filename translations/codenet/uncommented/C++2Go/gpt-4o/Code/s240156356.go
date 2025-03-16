package main

import (
	"fmt"
	"sort"
)

func main() {
	var str1, str2 string
	fmt.Scan(&str1, &str2)

	// Convert strings to slices of runes for sorting
	runes1 := []rune(str1)
	runes2 := []rune(str2)

	// Sort str1 in ascending order
	sort.Slice(runes1, func(i, j int) bool {
		return runes1[i] < runes1[j]
	})

	// Sort str2 in descending order
	sort.Slice(runes2, func(i, j int) bool {
		return runes2[i] > runes2[j]
	})

	loop := len(runes1)
	if len(runes2) < loop {
		loop = len(runes2)
	}
	flag := false

	for i := 0; i < loop; i++ {
		ch1 := runes1[i]
		ch2 := runes2[i]

		if ch1 == ch2 {
			if loop == i+1 && len(runes1) < len(runes2) {
				flag = true
				break
			} else {
				continue
			}
		} else {
			if ch2 > ch1 {
				flag = true
				break
			} else {
				break
			}
		}
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
