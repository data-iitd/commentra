package main

import (
	"fmt"
)

func allSame(arr []int) bool {
	for _, x := range arr {
		if x != arr[0] {
			return false
		}
	}
	return true
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	elems := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&elems[i])
	}

	if allSame(elems) {
		fmt.Println(0)
		return
	}
	if k == 1 {
		fmt.Println(-1)
		return
	}
	if !allSame(elems[k-1:]) {
		fmt.Println(-1)
		return
	}

	target := elems[len(elems)-1]
	toDelete := elems[:k-1]

	for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
		toDelete = toDelete[:len(toDelete)-1]
	}
	fmt.Println(len(toDelete))
}

// <END-OF-CODE>
