package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	sort.Ints(arr)

	sum := 0
	for i := 0; i < k; i++ {
		sum += arr[i]
	}

	fmt.Println(sum)
}

// <END-OF-CODE>
