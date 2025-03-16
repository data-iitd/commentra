package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N)

	M := 1000000
	Nsq := 1000

	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}

	// Initialize the factorial table
	fact := make([]int64, M)
	fact[0] = 1

	// Compute the factorial table
	for n := 1; n < M; n++ {
		fact[n] = fact[n-1] * int64(n) % MOD
	}

	// Compute the inverse factorial values
	inv := make([]int64, N)
	inv[0] = 1
	for i := 1; i < N; i++ {
		inv[i] = inv[i-1] * int64(i+1) % MOD
	}

	// Compute the temporary value
	temp := make([]int64, N)
	for j := 0; j < N; j++ {
		temp[j] = (inv[j] + inv[N-1-j] - 1) % MOD
	}

	// Compute the final answer
	var ans int64 = 0
	for i := 0; i < N; i++ {
		ans += A[i] * temp[i] % MOD
		ans %= MOD
	}

	// Multiply the final answer with the factorial of N
	ans *= fact[N]
	ans %= MOD

	// Print the final answer
	fmt.Fprintln(writer, ans)
}

