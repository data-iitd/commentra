package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	N, _ := strconv.Atoi(scanner.Text())
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(scanner.Text())
	}
	if possible(N, A) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func possible(N int, A []int) bool {
	sum := 0
	for i := 0; i < N; i++ {
		sum += A[i]
	}
	NS := (N * (N + 1)) / 2
	if sum%NS!= 0 {
		return false
	}
	K := sum / NS
	for i := 0; i < N; i++ {
		j := i == 0? N - 1 : i - 1
		d := K - (A[i] - A[j])
		if d < 0 || d%N!= 0 {
			return false
		}
	}
	return true
}

