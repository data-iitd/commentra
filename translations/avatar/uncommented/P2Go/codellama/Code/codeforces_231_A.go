package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	var c int
	for i := 0; i < n; i++ {
		var l1 []int
		fmt.Scan(&l1)
		if sum(l1) > 1 {
			c++
		}
	}
	fmt.Println(c)
}

func sum(l1 []int) int {
	var s int
	for _, v := range l1 {
		s += v
	}
	return s
}

