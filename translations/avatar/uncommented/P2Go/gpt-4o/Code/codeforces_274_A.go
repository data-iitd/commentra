package main

import (
	"fmt"
	"sort"
)

func main() {
	var num, k int
	fmt.Scan(&num, &k)

	arr := make([]int, num)
	for i := 0; i < num; i++ {
		fmt.Scan(&arr[i])
	}

	different := make(map[int]struct{})
	temp := 0

	sort.Ints(arr)

	for _, x := range arr {
		if x%k != 0 || _, exists := different[x/k]; !exists {
			different[x] = struct{}{}
		}
		temp = max(len(different), temp)
	}

	fmt.Println(temp)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>
