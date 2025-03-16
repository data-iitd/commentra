package main

import (
	"fmt"
)

func main() {
	var v [10]int
	sum := 0

	for i := 0; i < 10; i++ {
		fmt.Scan(&v[i])
	}

	for i := 0; i < 10; i++ {
		sum += v[i]
	}

	fmt.Println(sum)
}

// <END-OF-CODE>
