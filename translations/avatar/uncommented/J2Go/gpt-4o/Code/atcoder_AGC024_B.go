package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	P := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&P[i])
		P[i]-- // Adjusting to 0-based index
	}

	mapIndex := make(map[int]int)
	for i := 0; i < N; i++ {
		mapIndex[P[i]] = i
	}

	nglist := []int{}
	for i := 0; i < N-1; i++ {
		if mapIndex[i] > mapIndex[i+1] {
			nglist = append(nglist, i)
		}
	}

	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}

	ans := min(N-nglist[0]-1, nglist[len(nglist)-1]+1)
	for i := 0; i < len(nglist)-1; i++ {
		ans = min(nglist[i]+1+N-nglist[i+1]-1, ans)
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
