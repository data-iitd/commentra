
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var N, x int64
	fmt.Fscanf(reader, "%d\n", &N)
	fmt.Fscanf(reader, "%d\n", &x)

	srimeList := make([]int64, N)
	for i := int64(0); i < N; i++ {
		fmt.Fscanf(reader, "%d\n", &srimeList[i])
	}

	costList := make([][]int64, N)
	for i := int64(0); i < N; i++ {
		costList[i] = make([]int64, N)
		costList[i][0] = srimeList[i]
		for castNum := int64(1); castNum < N; castNum++ {
			costList[i][castNum] = int64(
				min(
					costList[i][castNum-1],
					srimeList[(i-castNum+N)%N],
				),
			)
		}
	}

	result := make([]int64, N)
	for i := int64(0); i < N; i++ {
		result[i] = i*x + sum(costList[i])
	}

	fmt.Println(min(result...))
}

func min(a...int64) int64 {
	min := a[0]
	for _, v := range a {
		if v < min {
			min = v
		}
	}
	return min
}

func sum(a []int64) int64 {
	sum := int64(0)
	for _, v := range a {
		sum += v
	}
	return sum
}

// 