package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	ans := make([]int, n)

	for i := 0; i < n-1; i++ {
		var a int
		fmt.Scan(&a)
		a-- // Decrement the vertex index as it is 0-indexed
		ans[a]++ // Increment the count of the vertex
	}

	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

