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
	parts := bufio.NewScanner(strings.NewReader(input))
	parts.Split(bufio.ScanWords)

	var N, X int
	var A []int

	for parts.Scan() {
		num, _ := strconv.Atoi(parts.Text())
		A = append(A, num)
	}

	N = A[0]
	X = A[1]
	A = A[2:]

	S := make([]int, N)
	S[0] = A[0]
	for i := 1; i < N; i++ {
		S[i] = S[i-1] + A[i]
	}

	ans := float64(1e18)
	for k := 1; k <= N; k++ {
		E := k * X + 2 * sumBackwards(S, N-2*k-1, k)
		if E < ans {
			ans = E
		}
	}

	result := ans + float64(N*X) + 5*float64(S[N-1])
	fmt.Println(result)
}

func sumBackwards(arr []int, start, step int) int {
	sum := 0
	for i := start; i >= 0; i -= step {
		sum += arr[i]
	}
	return sum
}
