
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize the answer to 0
	ans := 0

	// Create a scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of test cases from standard input
	scanner.Scan()
	N := int(mustParseInt(scanner.Text()))

	// Iterate through all numbers from 1 to N
	for i := 1; i <= N; i++ {
		// Calculate the contribution of i to the answer
		// The formula is given by the problem statement
		ans += i * (N / i) * (N / i + 1) / 2
	}

	// Print the answer
	fmt.Println(ans)
}

func mustParseInt(s string) int {
	n, err := strconv.Atoi(s)
	if err!= nil {
		panic(err)
	}
	return n
}

