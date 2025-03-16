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

	// Create a map to map each value in P to its index
	m := make(map[int]int)
	for i := 0; i < N; i++ {
		m[P[i]] = i
	}

	// Create a list to store indices of elements that are out of order
	nglist := make([]int, 0)
	for i := 0; i < N-1; i++ {
		if m[i] > m[i+1] {
			nglist = append(nglist, i)
		}
	}

	// If nglist is empty, the array P is already sorted
	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}

	// Calculate the minimum number of swaps required to sort the array P
	ans := math.Min(float64(N-nglist[0]-1), float64(nglist[len(nglist)-1]+1))
	for i := 0; i < len(nglist)-1; i++ {
		ans = math.Min(float64(nglist[i]+1+N-nglist[i+1]-1), ans)
	}

	// Print the minimum number of swaps required
	fmt.Println(int(ans))
}

