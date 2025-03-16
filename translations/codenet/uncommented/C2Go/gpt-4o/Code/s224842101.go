package main

import (
	"fmt"
)

func main() {
	var a, b int
	count := make([]int, 4)

	for i := 0; i < 3; i++ {
		fmt.Scan(&a, &b)
		count[a-1]++
		count[b-1]++
	}

	s := 1
	for i := 0; i < 4; i++ {
		s *= count[i]
	}

	if s == 4 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
