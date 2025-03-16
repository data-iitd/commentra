package main

import (
	"fmt"
	"math"
)

func find(s string, ch rune) []int {
	var indices []int
	for i, ltr := range s {
		if ltr == ch {
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

	if !containsRune(s, '0') {
		fmt.Println(n - 1)
	} else {
		indices := find(s, '0')
		if len(indices) == 1 {
			fmt.Println(n)
		} else {
			maximum := 0
			for i := 0; i < len(indices); i++ {
				for j := i + 1; j < len(indices); j++ {
					x0 := indices[i]
					x1 := indices[j]
					distance := 2 + 2*(math.Abs(float64(i-j))-1) - (math.Abs(float64(x0-x1)) - 1)
					if distance > float64(maximum) {
						maximum = int(distance)
					}
				}
			}
			countOfOnes := countRune(s, '1')
			fmt.Println(countOfOnes + maximum)
		}
	}
}

func containsRune(s string, ch rune) bool {
	for _, ltr := range s {
		if ltr == ch {
			return true
		}
	}
	return false
}

func countRune(s string, ch rune) int {
	count := 0
	for _, ltr := range s {
		if ltr == ch {
			count++
		}
	}
	return count
}
