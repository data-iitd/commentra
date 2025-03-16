package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	var A []int
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		A = append(A, x)
	}

	mn, mx := N+1, -1

	for i := 0; i < N; i++ {
		if (i+1 != A[i]) {
			mn = min(mn, i)
			mx = max(mx, i)
		}
	}

	if mx == -1 {
		fmt.Println("0 0")
	} else {
		temp := append([]int{}, A[:mn]...)
		temp = append(temp, A[mn:(mx+1)]...)
		temp = append(temp, A[(mx+1):]...)
		reversed := reverse(temp)

		if sort.IntsAreSorted(reversed) {
			fmt.Println(mn+1, mx+1)
		} else {
			fmt.Println("0 0")
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func reverse(arr []int) []int {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
	return arr
}

