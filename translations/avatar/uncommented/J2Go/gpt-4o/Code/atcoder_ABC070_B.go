package main

import (
	"fmt"
	"sort"
)

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)

	if c > b {
		fmt.Println(0)
	} else if a > d {
		fmt.Println(0)
	} else if a < c {
		fmt.Println(min(b, d) - c)
	} else {
		l := []int{a, b, c, d}
		sort.Ints(l)
		fmt.Println(l[2] - l[1])
	}
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// <END-OF-CODE>
