package main

import (
	"fmt"
)

func main() {
	var n, i int
	var h [100001]int
	var max, flag int = -1, 0

	fmt.Scan(&n)

	for i = 0; i < n; i++ {
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

