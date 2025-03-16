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
	fmt.Println("Enter the number of elements in the list:")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the cost multiplier:")
	x, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadString('\n')), 10, 64)
	fmt.Println("Enter the elements of the list:")
	srimeList := make([]int64, N)
	for i := 0; i < N; i++ {
		srimeList[i], _ = strconv.ParseInt(strings.TrimSpace(reader.ReadString('\n')), 10, 64)
	}

	costList := make([][]int64, N)
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N)
	}

	// Fill costList with the minimum costs for each element in srimeList
	for i := 0; i < N; i++ {
		costList[i][0] = srimeList[i]
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = int64(min(costList[i][castNum-1], srimeList[(i-castNum+N)%N]))
		}
	}

	result := make([]int64, N)
	for i := 0; i < N; i++ {
		j := i
		result[i] = int64(i*int(x) + int64(sum(costList[j])))
	}

	// Print the minimum cost found
	fmt.Println(min(result))
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func sum(a []int64) int {
	sum := 0
	for _, i := range a {
		sum += int(i)
	}
	return sum
}

