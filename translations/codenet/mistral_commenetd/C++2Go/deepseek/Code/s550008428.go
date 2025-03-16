package main

import (
	"fmt"
	"sort"
)

func main() {
	var s, x, d int
	d = 2

	fmt.Scan(&s)
	a := make(map[int]bool)
	a[s] = true

	for {
		if s%2 == 0 {
			x = s / 2
			if _, exists := a[x]; exists {
				fmt.Println(d)
				return
			}
			a[x] = true
		} else {
			x = 3*s + 1
			if _, exists := a[x]; exists {
				fmt.Println(d)
				return
			}
			a[x] = true
		}
		s = x
		d++
	}

	fmt.Println(d)
}

