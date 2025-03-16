package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	var taro, hanako int
	fmt.Scan(&n)

	t := make([]string, n)
	h := make([]string, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&t[i])
		fmt.Scan(&h[i])
		if strings.Compare(t[i], h[i]) < 0 {
			hanako += 3
		}
		if strings.Compare(t[i], h[i]) > 0 {
			taro += 3
		}
		if strings.Compare(t[i], h[i]) == 0 {
			taro += 1
			hanako += 1
		}
	}

	fmt.Printf("%d %d\n", taro, hanako)
}

