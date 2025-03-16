package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	h := make([]int, n)
	max := -1
	flag := 0

	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
		if max < h[i] {
			max = h[i]
		}

		if max-h[i] >= 2 {
			flag = 1
		}
	}

	if flag == 1 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

