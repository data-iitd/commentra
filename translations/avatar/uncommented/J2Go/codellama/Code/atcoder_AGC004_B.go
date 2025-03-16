
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

	fmt.Scan(&N)
	fmt.Scan(&x)

	for i := 0; i < N; i++ {
		var srime int64
		fmt.Scan(&srime)
		srimeList = append(srimeList, srime)
	}

	for i := 0; i < N; i++ {
		costList = append(costList, make([]int64, N))
	}

	for i := 0; i < N; i++ {
		costList[i][0] = srimeList[i]
		for j := 1; j < N; j++ {
			costList[i][j] = int64(math.Min(float64(costList[i][j-1]), float64(srimeList[(i-j+N)%N])))
		}
	}

	for i := 0; i < N; i++ {
		result = append(result, int64(i)*x+costList[i][N-1])
	}

	fmt.Println(result[0])

	for i := 1; i < N; i++ {
		if result[i] < result[0] {
			result[0] = result[i]
		}
	}

	fmt.Println(result[0])
}

