package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize FastReader for input
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of integers to process
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())

	// Array to count occurrences of integers based on their bit count
	a := make([]int, 33)

	// Process each integer and count how many have the same number of set bits
	for i := 0; i < n; i++ {
		sc.Scan()
		x, _ := strconv.ParseInt(sc.Text(), 10, 64)
		a[rec(x)]++
	}

	// Variable to accumulate the final answer
	answer := 0.0

	// Calculate the contribution to the answer from each bit count
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]-1)) / 2.0 * float64(a[i]-1)
		answer += summ
	}

	// Print the final answer as a long integer
	fmt.Println(int64(answer))
}

// Method to count the number of set bits (1s) in the binary representation of x
func rec(x int64) int {
	answer := 0
	// Iterate through each bit position from 31 to 0
	for k := 31; k >= 0; k-- {
		// Check if the k-th bit is set
		if (x & (1 << k)) != 0 {
			answer++
		}
	}
	return answer
}
