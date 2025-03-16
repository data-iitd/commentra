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

	for _, i := range l {
		if contains(l, i+1) && contains(l, i+2) {
			fmt.Println("YES")
			return
		}
	}
	fmt.Println("NO")
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

