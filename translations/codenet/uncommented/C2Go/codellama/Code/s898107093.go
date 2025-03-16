package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scanln(&n)
	t := make([]string, n)
	h := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scanln(&t[i])
		fmt.Scanln(&h[i])
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
	fmt.Println(taro, hanako)
}

