package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	number := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&number[i])
	}

	h1, h2 := 0, 0
	x := 0

	for i := 0; i < n; i++ {
		if number[i] != 4 && number[i] != 7 {
			fmt.Println("NO")
			x++
			break
		}
		if i < n/2 {
			h1 += number[i]
		} else {
			h2 += number[i]
		}
	}

	if x == 0 {
		if h1 == h2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

// <END-OF-CODE>
