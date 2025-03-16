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

	found := false
	for _, i := range l {
		if contains(l, i+1) && contains(l, i+2) {
			fmt.Println("YES")
			found = true
			break
		}
	}

	if !found {
		fmt.Println("NO")
	}
}

func contains(slice []int, value int) bool {
	for _, v := range slice {
		if v == value {
			return true
		}
	}
	return false
}

// <END-OF-CODE>
