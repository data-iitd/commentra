package main

import (
	"fmt"
)

func main() {
	var s, x, d int = 0, 0, 2
	fmt.Scan(&s)
	a := make(map[int]struct{})
	a[s] = struct{}{}

	for {
		if s%2 == 0 {
			x = s / 2
			if _, exists := a[x]; exists {
				fmt.Println(d)
				return
			}
			a[x] = struct{}{}
		} else {
			x = 3*s + 1
			if _, exists := a[x]; exists {
				fmt.Println(d)
				return
			}
			a[x] = struct{}{}
		}
		s = x
		d++
	}

	fmt.Println(d)
}

// <END-OF-CODE>
