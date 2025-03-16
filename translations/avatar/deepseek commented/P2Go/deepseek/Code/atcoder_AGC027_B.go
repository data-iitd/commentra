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
	scanner.Scan()
	input := scanner.Text()
	parts := strings.Split(input, " ")

	N, _ := strconv.Atoi(parts[0])
	X, _ := strconv.Atoi(parts[1])
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = i + 1
	}

	S := make([]int, N)
	S[0] = A[0]
	for i := 1; i < N; i++ {
		S[i] = S[i-1] + A[i]
	}

	ans := float64(1e18)

	for k := 1; k <= N; k++ {
		E := k * X
		for j := N - 2*k - 1; j >= 0; j -= k {
			E += 2 * S[j]
		}
		if E < ans {
			ans = E
		}
	}

	finalResult := ans + float64(N*X+5*S[N-1])
	fmt.Println(finalResult)
}
