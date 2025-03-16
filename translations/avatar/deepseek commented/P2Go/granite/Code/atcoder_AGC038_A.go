

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(H int, W int, A int, B int) {
	// Initialize the answer matrix with "0"
	answer := make([][]string, H)
	for i := 0; i < H; i++ {
		answer[i] = make([]string, W)
		for j := 0; j < W; j++ {
			answer[i][j] = "0"
		}
	}

	// Fill the matrix based on the given conditions
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if i < B { // Check if the row index is less than B
				if j < A { // Check if the column index is less than A
					answer[i][j] = "0" // Assign "0" if both conditions are met
				} else {
					answer[i][j] = "1" // Assign "1" otherwise
				}
			} else { // If the row index is not less than B
				if j < A {
					answer[i][j] = "1" // Assign "1" if the column index is less than A
				} else {
					answer[i][j] = "0" // Assign "0" otherwise
				}
			}
		}
	}

	// Print each row of the matrix as a string
	for i := 0; i < H; i++ {
		fmt.Println(strings.Join(answer[i], ""))
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var H int
	scanner.Scan()
	H, _ = strconv.Atoi(scanner.Text())
	var W int
	scanner.Scan()
	W, _ = strconv.Atoi(scanner.Text())
	var A int
	scanner.Scan()
	A, _ = strconv.Atoi(scanner.Text())
	var B int
	scanner.Scan()
	B, _ = strconv.Atoi(scanner.Text())
	solve(H, W, A, B)
}

