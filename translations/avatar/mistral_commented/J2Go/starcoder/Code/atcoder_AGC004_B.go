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
	var N int
	var x int64
	N, _ = strconv.Atoi(readLine(reader))
	x, _ = strconv.ParseInt(readLine(reader), 10, 64)
	srimeList := make([]int64, N)
	for i := 0; i < N; i++ {
		srimeList[i], _ = strconv.ParseInt(readLine(reader), 10, 64)
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
		temp := int64(i) * x
		for _, cost := range costList[i] {
			temp += cost
		}
		result[i] = temp
	}
	fmt.Println(min(result))
}

func min(arr []int64) int64 {
	min := arr[0]
	for _, val := range arr {
		if val < min {
			min = val
		}
	}
	return min
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

