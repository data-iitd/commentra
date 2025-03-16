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
	fmt.Println("Enter the number of elements in the array")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the value of L")
	L, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the value of R")
	R, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the value of QL")
	QL, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the value of QR")
	QR, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	W := make([]int, N)
	sum := make([]int, N+1)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < N; i++ {
		W[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		sum[i+1] = sum[i] + W[i]
	}
	min := int64(1e18)
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount
		cand := int64(sum[lCount]*L + (sum[N] - sum[lCount])*R)
		llCount := int(max(0, float64(lCount-rCount-1)))
		rrCount := int(max(0, float64(rCount-lCount-1)))
		cand += int64(llCount*QL)
		cand += int64(rrCount*QR)
		min = min(min, cand)
	}
	fmt.Println(min)
}

func max(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

