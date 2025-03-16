
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Macro definitions for loop iterations
func rep(i, n int) {
	for i = 0; i < n; i++ {
		// Do something
	}
}

func rep1(i, n int) {
	for i = 1; i < n; i++ {
		// Do something
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var H, W int
	scanner.Scan()
	H, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	W, _ = strconv.Atoi(scanner.Text())

	var ans int
	// Check if either height or width is 1
	if H == 1 || W == 1 {
		ans = 1 // If either dimension is 1, the answer is 1
	} else {
		m := H * W // Calculate the total number of cells (H * W)
		// Check if the total number of cells is even or odd
		if m%2 == 0 {
			ans = m / 2 // If even, half of the cells can be filled
		} else {
			ans = m/2 + 1 // If odd, half plus one cell can be filled
		}
	}

	fmt.Println(ans) // Output the final answer
}

