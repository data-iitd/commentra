
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var A, B, C, K int
	fmt.Fscanf(reader, "%d %d %d %d\n", &A, &B, &C, &K)

	if A+B >= K {
		fmt.Println(min(A, K))
	} else {
		fmt.Println(A - (K - (A + B)))
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

