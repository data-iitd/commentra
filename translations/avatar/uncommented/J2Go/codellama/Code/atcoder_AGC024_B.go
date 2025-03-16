package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	P := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&P[i])
		P[i]--
	}
	map := make(map[int]int)
	for i := 0; i < N; i++ {
		map[P[i]] = i
	}
	nglist := make([]int, 0)
	for i := 0; i < N-1; i++ {
		if map[i] > map[i+1] {
			nglist = append(nglist, i)
		}
	}
	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}
	ans := math.Min(float64(N-nglist[0]-1), float64(nglist[len(nglist)-1]+1))
	for i := 0; i < len(nglist)-1; i++ {
		ans = math.Min(float64(nglist[i]+1+N-nglist[i+1]-1), ans)
	}
	fmt.Println(int(ans))
}

