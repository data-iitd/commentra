package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func solve(N int, x []int, y []int) {
	indices := make([]int, N)
	for i := 0; i < N; i++ {
		indices[i] = i
	}

	var totalDistances []float64
	permutations := permute(indices)

	for _, permutation := range permutations {
		totalDistance := 0.0
		for i := 0; i < N-1; i++ {
			f := permutation[i]
			t := permutation[i+1]
			distance := math.Sqrt(float64((x[t]-x[f])*(x[t]-x[f]) + (y[t]-y[f])*(y[t]-y[f])))
			totalDistance += distance
		}
		totalDistances = append(totalDistances, totalDistance)
	}

	var sum float64
	for _, d := range totalDistances {
		sum += d
	}
	result := sum / float64(len(totalDistances))
	fmt.Println(result)
}

func permute(arr []int) [][]int {
	var result [][]int
	permuteHelper(arr, 0, &result)
	return result
}

func permuteHelper(arr []int, start int, result *[][]int) {
	if start == len(arr) {
		perm := make([]int, len(arr))
		copy(perm, arr)
		*result = append(*result, perm)
		return
	}
	for i := start; i < len(arr); i++ {
		arr[start], arr[i] = arr[i], arr[start]
		permuteHelper(arr, start+1, result)
		arr[start], arr[i] = arr[i], arr[start] // backtrack
	}
}

func main() {
	var N int
	fmt.Scan(&N)
	x := make([]int, N)
	y := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])
		fmt.Scan(&y[i])
	}

	solve(N, x, y)
}

// <END-OF-CODE>
