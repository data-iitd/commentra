package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables N and D, which are integers between 1 and 20
	var N, D int
	// Read two integers from standard input
	N, _ = strconv.Atoi(strings.TrimSpace(os.Args[1]))
	D, _ = strconv.Atoi(strings.TrimSpace(os.Args[2]))

	// Calculate the number of complete groups of size (D*2 + 1) that can be formed from N
	ans := N / (D*2 + 1)
	// Calculate the remainder when N is divided by (D*2 + 1)
	rem := N % (D*2 + 1)

	// If there is a remainder, it means we need one additional group
	if rem!= 0 {
		ans = ans + 1 // Increment the answer by 1
	}

	// Output the final answer
	fmt.Printf("%d\n", ans)
}

