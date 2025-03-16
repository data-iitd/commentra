package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	x, _ := strconv.ParseInt(scanner.Text(), 10, 64)

	srimeList := make([]int64, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		srimeList[i], _ = strconv.ParseInt(scanner.Text(), 10, 64)
	}

	costList := make([][]int64, N)
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N)
	}

	for i := 0; i < N; i++ {
		costList[i][0] = srimeList[i]
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = min(costList[i][castNum-1], srimeList[(i-castNum+N)%N])
		}
	}

	result := make([]int64, N)
	for i := 0; i < N; i++ {
		var sum int64 = 0
		for j := 0; j < N; j++ {
			sum += costList[j][i]
		}
		result[i] = i*x + sum
	}

	minResult := result[0]
	for _, v := range result {
		if v < minResult {
			minResult = v
		}
	}

	fmt.Println(minResult)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

