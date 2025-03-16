
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

	var N, T int
	fmt.Fscanf(reader, "%d %d\n", &N, &T)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%d", &A[i])
	}

	m := A[0]
	B := make([]int, N)
	B[1] = A[1] - m
	m = int(math.Min(float64(m), float64(A[1])))
	for i := 2; i < N; i++ {
		B[i] = A[i] - m
		m = int(math.Min(float64(m), float64(A[i])))
	}

	maxValue := *max(B)
	count := 0
	for _, v := range B {
		if v == maxValue {
			count++
		}
	}
	fmt.Println(count)
}

func max(a []int) *int {
	max := a[0]
	for _, v := range a {
		if v > max {
			max = v
		}
	}
	return &max
}

