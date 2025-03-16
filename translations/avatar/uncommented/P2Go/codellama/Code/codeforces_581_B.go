package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	ans := make([]int, n)
	mx := arr[n-1]
	for i := n - 2; i >= 0; i-- {
		ans[i] = max(0, mx-arr[i]+1)
		if arr[i] > mx {
			mx = arr[i]
		}
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

