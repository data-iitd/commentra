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
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	N, _ := strconv.Atoi(parts[0])
	T, _ := strconv.Atoi(parts[1])

	A := make([]int, N)
	B := make([]int, N)

	line, _ = reader.ReadString('\n')
	nums := strings.Split(strings.TrimSpace(line), " ")
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(nums[i])
	}

	m := A[0]
	B[1] = A[1] - m
	m = min(m, A[1])
	for i := 2; i < N; i++ {
		B[i] = A[i] - m
		m = min(m, A[i])
	}

	maxValue := B[1]
	for i := 2; i < N; i++ {
		if B[i] > maxValue {
			maxValue = B[i]
		}
	}

	count := 0
	for i := 0; i < N; i++ {
		if B[i] == maxValue {
			count++
		}
	}

	fmt.Println(count)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

