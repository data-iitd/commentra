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
	fmt.Println("Enter the number of casts")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(make([]byte, 1024))))
	fmt.Println("Enter the cost of each cast")
	x, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadString(make([]byte, 1024))), 10, 64)
	srimeList := make([]int64, N)
	for i := 0; i < N; i++ {
		srimeList[i], _ = strconv.ParseInt(strings.TrimSpace(reader.ReadString(make([]byte, 1024))), 10, 64)
	}
	costList := make([][]int64, N)
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N)
	}
	for i := 0; i < N; i++ {
		costList[i][0] = srimeList[i]
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = int64(min(int(costList[i][castNum-1]), int(srimeList[(i-castNum+N)%N])))
		}
	}
	result := make([]int64, N)
	for i := 0; i < N; i++ {
		j := i
		result[i] = int64(i*int(x) + int64(sum(costList[i])))
	}
	fmt.Println(min(result))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sum(a []int64) int64 {
	var sum int64
	for _, v := range a {
		sum += v
	}
	return sum
}

