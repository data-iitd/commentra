package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	sort.Ints(l)

	c := 0
	for _, i := range l {
		if i > c {
			c++
		}
	}
	fmt.Println(c + 1)
}

// <END-OF-CODE>
