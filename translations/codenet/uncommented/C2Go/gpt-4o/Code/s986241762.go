package main

import (
	"fmt"
)

func main() {
	var n int
	var sum int64 = 0
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 1; i < n; i++ {
		if a[i-1] > a[i] {
			sum += int64(a[i-1] - a[i])
			a[i] = a[i-1]
		}
	}
	fmt.Println(sum)
}

// <END-OF-CODE>
