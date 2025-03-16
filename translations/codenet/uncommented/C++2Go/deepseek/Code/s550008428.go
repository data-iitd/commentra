package main

import (
	"fmt"
	"strconv"
)

func main() {
	var s int
	fmt.Scan(&s)

	a := make(map[int]bool)
	a[s] = true
	d := 2

	for {
		if s%2 == 0 {
			x := s / 2
			if a[x] {
				fmt.Println(d)
				return
			}
			a[x] = true
		} else {
			x := 3*s + 1
			if a[x] {
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

