package main

import (
	"fmt"
)

func main() {
	var n int
	var max int = -1
	var flag int = 0
	h := make([]int, 100001)

	fmt.Scan(&n)

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

// <END-OF-CODE>
