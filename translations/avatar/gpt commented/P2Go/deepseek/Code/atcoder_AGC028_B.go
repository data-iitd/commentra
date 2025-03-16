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

	// Read the integer input N
	N, _ := strconv.Atoi(readLine(reader))

	// Define a constant for the maximum size
	M := 1000000

	// Read the array A from input and convert it to a slice of int64
	A := readIntArray(reader)

	// Define the size for factorial calculations
	Nsq := 1000

	// Initialize a 2D slice to store factorial values
	fact := make([][]int64, Nsq)
	for i := range fact {
		fact[i] = make([]int64, Nsq)
	}

	// Set the first factorial value
	fact[0][0] = 1

	// Compute factorial values for columns
	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[i][n] = fact[i][n-1] * fact[i][n] % MOD // Multiply current column by the previous column
		}
	}

	// Compute factorial values for rows
	for n := 1; n < Nsq; n++ {
		for i := 0; i < Nsq; i++ {
			fact[n][i] = fact[n-1][i] * fact[n][i] % MOD // Multiply current row by the previous row
		}
	}

	// Flatten the factorial array to 1D
	factFlat := make([]int64, Nsq*Nsq)
	for i := range factFlat {
		factFlat[i] = fact[i/Nsq][i%Nsq]
	}

	// Create a slice of indices from 0 to N-1
	j := make([]int, N)
	for i := 0; i < N; i++ {
		j[i] = i
	}

	// Calculate modular inverses of numbers from 1 to N
	inv := make([]int64, N)
	for i := 1; i <= N; i++ {
		inv[i-1] = modInverse(int64(i), MOD)
	}

	// Compute cumulative sum of inverses and take modulo
	cumInv := make([]int64, N)
	for i := 0; i < N; i++ {
		cumInv[i] = (cumInv[i-1] + inv[i]) % MOD
	}

	// Calculate temporary values based on the cumulative inverses
	temp := make([]int64, N)
	for i := 0; i < N; i++ {
		temp[i] = (cumInv[j[i]] + cumInv[N-1-j[i]] - 1 + MOD) % MOD
	}

	// Compute the final answer by multiplying A with temp and summing the result
	var ans int64 = 0
	for i := 0; i < N; i++ {
		ans = (ans + A[i]*temp[i]) % MOD
	}
	ans = (ans * factFlat[N]) % MOD

	// Print the final answer
	fmt.Fprintln(writer, ans)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}

func readIntArray(reader *bufio.Reader) []int64 {
	line, _ := reader.ReadString('\n')
	parts := strings.Split(line[:len(line)-1], " ")
	intArray := make([]int64, len(parts))
	for i, part := range parts {
		intArray[i], _ = strconv.ParseInt(part, 10, 64)
	}
	return intArray
}

func modInverse(a, m int64) int64 {
	m0, x0, x1 := m, int64(0), int64(1)
	if m == 1 {
		return 0
	}
	for a > 1 {
		q := a / m
		m, a = a%m, m
		x0, x1 = x1-q*x0, x0
	}
	if x1 < 0 {
		x1 += m0
	}
	return x1
}

