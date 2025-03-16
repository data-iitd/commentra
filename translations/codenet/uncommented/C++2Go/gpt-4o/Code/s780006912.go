package main

import (
	"fmt"
)

func main() {
	var n int
	var array [100]int

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&array[i])
	}

	sum := 0
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			sum += array[i] * array[j]
		}
	}

	fmt.Println(sum)
}

// <END-OF-CODE>
