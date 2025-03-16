package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	i, j := 1, n*n
	for i < j {
		fmt.Println(i, j)
		i++
		j--
	}
}

// <END-OF-CODE>
