package main

import (
	"fmt"
)

func main() {
	var y int
	fmt.Scan(&y)

	var n int
	fmt.Scan(&n)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			for k := 0; k < n; k++ {
				if arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i]+arr[j] {
					fmt.Println(k+1, j+1, i+1)
					return
				}
			}
		}
	}
	fmt.Println(-1)
}

// <END-OF-CODE>
