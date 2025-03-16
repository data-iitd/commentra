package main

import (
	"fmt"
	"math"
	"sort"
)

func solve(N int, x []int, y []int) {
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}
	var permutations [][]int
	permute(indices, 0, N-1, &permutations)
	distances := []float64{}
	for _, permutation := range permutations {
		totalDistance := 0.0
		for i := 0; i < N-1; i++ {
			f, t := permutation[i], permutation[i+1]
			distance := math.Sqrt(float64((x[t]-x[f])*(x[t]-x[f]) + (y[t]-y[f])*(y[t]-y[f])))
			totalDistance += distance
		}
		distances = append(distances, totalDistance)
	}
	sumDistances := 0.0
	for _, distance := range distances {
		sumDistances += distance
	}
	result := sumDistances / float64(len(distances))
	fmt.Println(result)
}

func permute(arr []int, l int, r int, permutations *[][]int) {
	if l == r {
		perm := make([]int, len(arr))
		copy(perm, arr)
		*permutations = append(*permutations, perm)
	} else {
		for i := l; i <= r; i++ {
			arr[l], arr[i] = arr[i], arr[l]
			permute(arr, l+1, r, permutations)
			arr[l], arr[i] = arr[i], arr[l] // backtrack
		}
	}
}

func main() {
	var N int
	var x, y []int
	fmt.Scan(&N)
	x = make([]int, N)
	y = make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i], &y[i])
	}
	solve(N, x, y)
}

