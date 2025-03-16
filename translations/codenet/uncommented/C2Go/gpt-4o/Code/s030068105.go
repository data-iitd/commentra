package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	data := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&data[i])
	}

	max := 0
	index := -1
	for i := 0; i < n; i++ {
		if data[i] > max {
			max = data[i]
			index = i
		}
	}

	a := 0
	for i := 0; i < n; i++ {
		if i != index {
			a += data[i]
		}
	}

	if a > max {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
