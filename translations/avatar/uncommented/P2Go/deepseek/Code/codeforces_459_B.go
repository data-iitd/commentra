package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	var l1 []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		l1 = append(l1, x)
	}

	sort.Ints(l1)

	a := l1[len(l1)-1]
	b := l1[0]

	if a == b {
		fmt.Println(a-b, n*(n-1)/2)
	} else {
		ac := 0
		bc := 0
		for _, v := range l1 {
			if v == a {
				ac++
			}
			if v == b {
				bc++
			}
		}
		fmt.Println(a-b, ac*bc)
	}
}

