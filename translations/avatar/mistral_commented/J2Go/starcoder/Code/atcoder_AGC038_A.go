package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read input values for H, W, A, and B
	H, _ := strconv.Atoi(readLine(reader))
	W, _ := strconv.Atoi(readLine(reader))
	A, _ := strconv.Atoi(readLine(reader))
	B, _ := strconv.Atoi(readLine(reader))

	// Check if the grid dimensions meet the conditions
	if W < 2*A || H < 2*B {
		fmt.Println(-1)
		return
	}

	// Write the grid to the output
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			// Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
			if (i < B && j < A) || (i >= B) && (j >= A) {
				writer.WriteByte('0')
			} else {
				writer.WriteByte('1')
			}
		}
		writer.WriteByte('\n')
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

