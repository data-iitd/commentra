package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	data := strings.Fields(input)
	N, _ := strconv.Atoi(data[0])
	T, _ := strconv.Atoi(data[1])
	A := make([]int, N)
	B := make([]int, N)
	input, _ = reader.ReadString('\n')
	data = strings.Fields(input)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(data[i])
	}
	m := A[0]
	B[0] = A[1] - m
	m = min(m, A[1])
	for i := 2; i < N; i++ {
		B[i-1] = A[i] - m
		m = min(m, A[i])
	}
	maxB := B[0]
	for i := 1; i < N; i++ {
		if B[i] > maxB {
			maxB = B[i]
		}
	}
	count := 0
	for i := 0; i < N; i++ {
		if B[i] == maxB {
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

