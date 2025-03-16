package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	var x int64
	fmt.Scan(&N)
	fmt.Scan(&x)

	srimeList := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&srimeList[i])
	}

	costList := make([][]int64, N)
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N)
		costList[i][0] = srimeList[i]
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = int64(math.Min(float64(costList[i][castNum-1]), float64(srimeList[(i-castNum+N)%N])))
		}
	}

	result := make([]int64, N)
	for i := 0; i < N; i++ {
		j := i
		sum := int64(0)
		for _, costArray := range costList {
			sum += costArray[j]
		}
		result[i] = int64(i)*x + sum
	}

	minResult := result[0]
	for _, val := range result {
		if val < minResult {
			minResult = val
		}
	}

	fmt.Println(minResult)
}

// <END-OF-CODE>
