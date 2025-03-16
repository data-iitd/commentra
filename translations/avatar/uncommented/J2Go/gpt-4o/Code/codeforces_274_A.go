package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	var k int64
	fmt.Scan(&n, &k)
	arr := make([]int64, n)
	set := make(map[int64]struct{})

	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	count := 0
	for i := 0; i < n; i++ {
		if arr[i]%k != 0 {
			count++
			set[arr[i]] = struct{}{}
		} else if _, exists := set[arr[i]/k]; !exists {
			count++
			set[arr[i]] = struct{}{}
		}
	}

	fmt.Println(count)
}

// <END-OF-CODE>
