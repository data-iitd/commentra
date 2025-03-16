package main

import (
	"fmt"
	"strconv"
)

func find(s string, ch byte) []int {
	var indices []int
	for i := 0; i < len(s); i++ {
		if s[i] == ch {
			indices = append(indices, i)
		}
	}
	return indices
}

func main() {
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)

	if !strings.Contains(s, "0") {
		fmt.Println(n - 1)
	} else {
		indices := find(s, '0')
		if len(indices) == 1 {
			fmt.Println(n)
		} else {
			maximum := 0
			for i := 0; i < len(indices)-1; i++ {
				for j := i + 1; j < len(indices); j++ {
					distance := 2 + 2*(j-i-1) - (indices[j]-indices[i]-1)
					if distance > maximum {
						maximum = distance
					}
				}
			}
			fmt.Println(strings.Count(s, "1") + maximum)
		}
	}
}
