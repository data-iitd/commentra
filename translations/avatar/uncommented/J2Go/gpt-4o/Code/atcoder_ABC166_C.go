package main

import (
	"fmt"
)

func main() {
	var N int
	var M int64
	fmt.Scan(&N)
	fmt.Scan(&M)

	H := make([]int64, N)
	ans := make([]bool, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&H[i])
		ans[i] = true
	}

	for i := int64(0); i < M; i++ {
		var temp1, temp2 int
		fmt.Scan(&temp1, &temp2)
		if H[temp1-1] < H[temp2-1] {
			ans[temp1-1] = false
		} else if H[temp1-1] > H[temp2-1] {
			ans[temp2-1] = false
		} else {
			ans[temp1-1] = false
			ans[temp2-1] = false
		}
	}

	ans2 := 0
	for i := 0; i < N; i++ {
		if ans[i] {
			ans2++
		}
	}

	fmt.Println(ans2)
}

// <END-OF-CODE>
