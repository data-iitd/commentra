package main

import (
	"fmt"
	"sort"
)

func main() {
	var s, x, d int
	fmt.Scan(&s)
	a := make([]int, 0)
	a = append(a, s)

	for {
		if s%2 == 0 {
			x = s / 2
			if sort.SearchInts(a, x) != len(a) {
				fmt.Println(d)
				return
			}
			a = append(a, x)
		} else {
			x = 3*s + 1
			if sort.SearchInts(a, x) != len(a) {
				fmt.Println(d)
				return
			}
			a = append(a, x)
		}
		s = x
		d++
	}

	fmt.Println(d)
}

