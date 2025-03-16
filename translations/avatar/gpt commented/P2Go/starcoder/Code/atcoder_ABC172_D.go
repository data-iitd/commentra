package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the integer N from input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Initialize the answer variable to accumulate the result
	ans := 0

	// Loop through each integer from 1 to N (inclusive)
	for i := 1; i <= N; i++ {
		// Calculate the contribution of the current integer i to the answer
		ans += i * (N / i) * (N/i + 1) / 2
	}

	// Print the final result
	fmt.Println(ans)
}

