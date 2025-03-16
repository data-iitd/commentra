package main

import (
	"fmt"
	"sort"
)

func s() string {
	var input string
	fmt.Scanln(&input)
	var a []int
	fmt.Scanln(&input)
	a = make([]int, len(input.split(" ")))
	for i := 0; i < len(a); i++ {
		a[i] = int(input[i])
	}
	sort.Ints(a)
	for i := 1; i < len(a); i++ {
		if a[i] != a[i-1] && a[i] < a[i-1]*2 {
			return "YES"
		}
	}
	return "NO"
}

func main() {
	fmt.Println(s())
}
