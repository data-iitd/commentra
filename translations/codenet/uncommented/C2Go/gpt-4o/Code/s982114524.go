package main

import (
	"fmt"
)

func main() {
	var N, x int
	x = 0
	fmt.Scan(&N)
	for i := 1; i <= N; i++ {
		x += i
	}
	fmt.Println(x)
}

// <END-OF-CODE>
