package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object for input and a BufferedWriter for output
	sc := bufio.NewScanner(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	// Read the dimensions of the grid and the parameters A and B
	H, _ := strconv.Atoi(sc.Text())
	W, _ := strconv.Atoi(sc.Text())
	A, _ := strconv.Atoi(sc.Text())
	B, _ := strconv.Atoi(sc.Text())

	// Check if the grid can accommodate the required number of 0s and 1s
	if W < 2*A || H < 2*B {
		fmt.Println(-1)
		return
	}

	// Generate the grid based on the parameters A and B
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			// Determine whether to write '0' or '1' based on the current position
			if (i < B && j < A) || (i >= B && j >= A) {
				bw.WriteByte('0')
			} else {
				bw.WriteByte('1')
			}
		}
		bw.WriteByte('\n')
	}

	// Flush the BufferedWriter to ensure all data is written out
	bw.Flush()
}

