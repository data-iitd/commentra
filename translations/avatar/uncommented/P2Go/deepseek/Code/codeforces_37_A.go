package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	var l []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		l = append(l, x)
	}

	sort.Ints(l)

	high := 1
	maximum := 1
	tower := n

	for i := 1; i < n; i++ {
		if l[i] == l[i-1] {
			tower--
			high++
		} else {
			if high > maximum {
				maximum = high
			}
			high = 1
		}
	}

	if high > maximum {
		maximum = high
	}

	fmt.Println(maximum, tower)
}

