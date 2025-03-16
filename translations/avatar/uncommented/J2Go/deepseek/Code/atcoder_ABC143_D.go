package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	L := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i])
	}
	sort.Ints(L)
	count := 0
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			a := L[i]
			b := L[j]
			res := find(L, j+1, a+b)
			count += res
		}
	}
	fmt.Println(count)
}

func find(li []int, from int, target int) int {
	low := from
	upp := len(li) - 1
	for low < upp {
		mid := (low + upp) / 2
		if li[mid] >= target {
			upp = mid
		} else {
			low = mid + 1
		}
	}
	if low >= len(li) || li[from] >= target {
		return 0
	}
	return low - from + 1
}

