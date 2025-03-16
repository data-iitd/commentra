
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
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
	srimeList := make([]int64, N)
	for i := 0; i < N; i++ {
		srimeList[i], _ = strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
	}
	costList := make([][]int64, N)
	for i := 0; i < N; i++ {
		costList[i] = make([]int64, N)
		costList[i][0] = srimeList[i]
		for castNum := 1; castNum < N; castNum++ {
			costList[i][castNum] = int64(min(int(costList[i][castNum-1]), int(srimeList[(i-castNum+N)%N])))
		}
	}
	result := make([]int64, N)
	for i := 0; i < N; i++ {
		result[i] = int64(i)*x + sum(costList[i])
	}
	fmt.Println(min(result...))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	panic(err)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sum(a []int64) int64 {
	sum := int64(0)
	for _, v := range a {
		sum += v
	}
	return sum
}

