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
			idx := (i - castNum + N) % N
			if costList[i][castNum-1] < srimeList[idx] {
				costList[i][castNum] = costList[i][castNum-1]
			} else {
				costList[i][castNum] = srimeList[idx]
			}
		}
	}

	result := make([]int64, N)
	for i := 0; i < N; i++ {
		var sum int64 = 0
		for j := 0; j < N; j++ {
			sum += costList[j][i]
		}
		result[i] = srimeList[i]*x + sum
	}

	minCost := result[0]
	for _, cost := range result {
		if cost < minCost {
			minCost = cost
		}
	}

	fmt.Println(minCost)
}

