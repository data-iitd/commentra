package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, a int
	fmt.Scan(&n)
	fmt.Scan(&a)
	sum := 0
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}
	sort.Ints(s)
	for i := n - 1; i > n-a-1; i-- {
		sum += s[i]
	}
	fmt.Println(sum)
}

// <END-OF-CODE>
