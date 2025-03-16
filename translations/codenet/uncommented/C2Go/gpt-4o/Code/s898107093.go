package main

import (
	"fmt"
)

func main() {
	var n, taro, hanako int
	fmt.Scan(&n)

	t := make([]string, n)
	h := make([]string, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&t[i])
		fmt.Scan(&h[i])
		if t[i] < h[i] {
			hanako += 3
		} else if t[i] > h[i] {
			taro += 3
		} else {
			taro += 1
			hanako += 1
		}
	}

	fmt.Printf("%d %d\n", taro, hanako)
}

// <END-OF-CODE>
