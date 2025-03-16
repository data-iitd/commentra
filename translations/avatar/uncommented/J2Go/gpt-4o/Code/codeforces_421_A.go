package main

import (
	"fmt"
)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)

	list1 := make(map[int]struct{})
	list2 := make(map[int]struct{})

	for i := 0; i < a; i++ {
		var num int
		fmt.Scan(&num)
		list1[num] = struct{}{}
	}

	for i := 0; i < b; i++ {
		var num int
		fmt.Scan(&num)
		list2[num] = struct{}{}
	}

	for i := 1; i <= n; i++ {
		if _, exists := list1[i]; exists {
			fmt.Print(1, " ")
		} else {
			fmt.Print(2, " ")
		}
	}
}

// <END-OF-CODE>
