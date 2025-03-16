package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define the modulo constant
const MOD = 1000000007

// Define the maximum size
const M = 1000001

// Define the size for factorial calculations
const Nsq = 1000

// Define a function to compute factorials
func factorial(n int) int {
	fact := make([]int, M)
	fact[0] = 1
	for i := 1; i < M; i++ {
		fact[i] = (fact[i - 1] * i) % MOD
	}
	return fact[n]
}

func main() {
	// Read the integer input N
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(reader.ReadString('\n'))

	// Read the array A from input and convert it to a slice of int64 type
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.ParseInt(reader.ReadString('\n'), 10, 64)
	}

	// Compute the final answer by multiplying A with temp and summing the result
	ans := int64(0)
	for i := 0; i < N; i++ {
		ans += (A[i] * (factorial(i) + factorial(N-1-i) - 1) % MOD)
	}
	ans %= MOD

	// Multiply the answer by the factorial of N and take modulo
	ans *= factorial(N)
	ans %= MOD

	// Print the final answer
	fmt.Println(ans)
}

