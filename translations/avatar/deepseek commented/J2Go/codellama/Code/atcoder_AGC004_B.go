package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	var x int64
	var srimeList []int64
	var costList [][]int64
	var result []int64

	// Read the number of elements N
	fmt.Scan(&N)

	// Read the cost multiplier x
	fmt.Scan(&x)

	// Read N long integers and add to srimeList
	for i := 0; i < N; i++ {
		var temp int64
		fmt.Scan(&temp)
		srimeList = append(srimeList, temp)
	}

	// Initialize each array in costList with size N
	for i := 0; i < N; i++ {
		costList = append(costList, make([]int64, N))
	}

	// Fill costList with the minimum costs for each element in srimeList
	for i := 0; i < N; i++ {
		costList[i][0] = srimeList[i]
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = int64(math.Min(float64(costList[i][castNum-1]), float64(srimeList[(i-castNum+N)%N])))
		}
	}

	// Initialize the final results
	for i := 0; i < N; i++ {
		result = append(result, int64(i)*x+costList[i][i])
	}

	// Print the minimum cost found
	fmt.Println(result)
}

