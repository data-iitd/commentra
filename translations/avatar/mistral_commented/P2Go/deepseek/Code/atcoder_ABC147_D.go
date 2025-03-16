package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the number of elements 'N' from the user
	var N int
	fmt.Fscan(reader, &N)

	// Read 'N' integers from the user and store them in a slice 'A'
	A := make([]int64, N)
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)
	for i := 0; i < N; i++ {
		scanner.Scan()
		num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		A[i] = num
	}

	// Initialize the result variable to zero
	var result int64 = 0

	// Iterate through each bit position 'b' from 0 to 59
	for b := 0; b < 60; b++ {
		// Calculate the sum of bits in position 'b' in all numbers of 'A'
		var bs int64 = 0
		for _, num := range A {
			bs += (num >> int64(b)) & 1
		}

		// Calculate the contribution of this bit position 'b' to the result
		contribution := bs * (int64(N) - bs) * (1 << uint(b))

		// Add this contribution to the result
		result = (result + contribution) % 1000000007
	}

	// Print the final result
	fmt.Fprintln(writer, result)
}

