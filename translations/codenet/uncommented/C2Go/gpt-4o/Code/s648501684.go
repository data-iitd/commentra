package main

import (
	"fmt"
)

func main() {
	var n, k, q int64

	fmt.Scan(&n, &k, &q)

	arr := make([]int64, n+1) // Create an array of size n+1

	for i := int64(0); i <= n; i++ {
		arr[i] = 0
	}

	for i := int64(0); i < q; i++ {
		var temp int64
		fmt.Scan(&temp)
		arr[temp] += 1
	}

	for i := int64(1); i <= n; i++ {
		if arr[i] > (q - k) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

// <END-OF-CODE>
