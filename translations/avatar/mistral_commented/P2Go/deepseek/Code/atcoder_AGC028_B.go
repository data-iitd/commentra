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

	// Read input number of elements N
	var N int
	fmt.Fscan(reader, &N)

	// Define a constant value for the size of the 2D array A
	const M = 1000000

	// Initialize 2D slice fact with given size and initial value 1
	fact := make([][]int64, 1000)
	for i := range fact {
		fact[i] = make([]int64, 1000)
		fact[i][0] = 1
	}

	// Calculate factorial for each cell in the 2D array fact using a loop
	for n := 1; n < 1000; n++ {
		for m := 1; m < 1000; m++ {
			fact[n][m] = fact[n][m-1] * fact[n-1][m] % MOD
		}
	}

	// Read input data into NumPy array A
	A := make([]int64, N)
	input, _ := reader.ReadString('\n')
	input = input[:len(input)-1] // Remove newline character
	nums := bufio.NewScanner(strings.NewReader(input))
	nums.Split(bufio.ScanWords)
	for i := 0; i < N; i++ {
		nums.Scan()
		A[i], _ = strconv.ParseInt(nums.Text(), 10, 64)
	}

	// Initialize NumPy array j with given size
	j := make([]int, N)

	// Calculate the inverse of each element in the array inv using a list comprehension
	inv := make([]int64, N)
	for i := 1; i <= N; i++ {
		inv[i-1] = powMod(i, MOD-2, MOD)
	}

	// Calculate cumulative sum of the array inv
	for i := 1; i < N; i++ {
		inv[i] = (inv[i] + inv[i-1]) % MOD
	}

	// Calculate temporary array temp using elements from j and inv
	temp := make([]int64, N)
	for i := 0; i < N; i++ {
		temp[i] = (inv[i] + inv[N-1-i] - 1 + MOD) % MOD
	}

	// Calculate the answer ans using given formula
	ans := int64(0)
	for i := 0; i < N; i++ {
		ans = (ans + A[i]*temp[i]) % MOD
	}

	// Multiply the answer ans with the last element of fact array
	ans = ans * fact[N-1][N-1] % MOD

	// Print the answer ans
	fmt.Fprintln(writer, ans)
}

// Helper function to perform modular exponentiation
func powMod(base, exp, mod int64) int64 {
	result := int64(1)
	base = base % mod
	for exp > 0 {
		if exp%2 == 1 {
			result = (result * base) % mod
		}
		exp = exp >> 1
		base = (base * base) % mod
	}
	return result
}

