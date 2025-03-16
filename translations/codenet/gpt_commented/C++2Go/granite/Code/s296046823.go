
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables N and K to hold the number of elements and the divisor respectively
	var N, K int

	// Read the values of N and K from standard input
	reader := bufio.NewReader(os.Stdin)
	N64, _ := strconv.ParseInt(read(reader), 10, 64)
	K64, _ := strconv.ParseInt(read(reader), 10, 64)
	N = int(N64)
	K = int(K64)

	// Initialize a slice of size N to store the input elements
	v := make([]int, N)

	// Read N integers from standard input and store them in the slice v
	for i := 0; i < N; i++ {
		v[i], _ = strconv.Atoi(read(reader))
	}

	// Calculate the number of groups needed based on the formula ceil((N-1) / (K-1))
	// This is done using integer arithmetic to avoid floating-point operations
	count := (N - 1) / (K - 1)
	if (N - 1)%(K-1)!= 0 {
		count++
	}

	// Output the calculated count of groups
	fmt.Println(count)
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

