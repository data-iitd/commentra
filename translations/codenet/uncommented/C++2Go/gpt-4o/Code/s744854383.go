package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	a := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&a[i])
	}

	idx := 1
	ans := 0
	for i := 0; i < N; i++ {
		if a[i] == idx {
			idx++
		} else {
			ans++
		}
	}

	if idx == 1 {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}

// <END-OF-CODE>
