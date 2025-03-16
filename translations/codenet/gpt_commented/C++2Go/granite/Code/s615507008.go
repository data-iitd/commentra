
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Function to solve the problem based on the given parameters
func solve(N int, T []int, M int, P []int, X []int) {
	// Iterate over each modification request
	for i := 0; i < M; i++ {
		ans := 0 // Initialize the answer for the current modification
		// Calculate the total time considering the current modification
		for j := 0; j < N; j++ {
			// If the current index matches the modified position, add the new time value
			if j == P[i]-1 {
				ans += X[i]
			} else { // Otherwise, add the original time value
				ans += T[j]
			}
		}
		// Output the result for the current modification
		fmt.Println(ans)
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var N int
	scanner.Scan()
	N = int(scanInt(scanner.Bytes()))
	T := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		T[i] = int(scanInt(scanner.Bytes()))
	}
	var M int
	scanner.Scan()
	M = int(scanInt(scanner.Bytes()))
	P := make([]int, M)
	X := make([]int, M)
	for i := 0; i < M; i++ {
		scanner.Scan()
		P[i] = int(scanInt(scanner.Bytes()))
		scanner.Scan()
		X[i] = int(scanInt(scanner.Bytes()))
	}
	solve(N, T, M, P, X)
}

func scanInt(bytes []byte) int64 {
	result := int64(0)
	sign := 1
	if bytes[0] == '-' {
		sign = -1
		bytes = bytes[1:]
	}
	for _, b := range bytes {
		result = result*10 + int64(b-'0')
	}
	return result * int64(sign)
}

// Translate the above Go code to C++ and end with comment "