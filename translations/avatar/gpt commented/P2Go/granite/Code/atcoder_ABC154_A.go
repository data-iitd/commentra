
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(S string, T string, A int, B int, U string) {
	// Check if the first string S matches the string U
	if S == U {
		A-- // Decrement A if S matches U
	}
	// Check if the second string T matches the string U
	if T == U {
		B-- // Decrement B if T matches U
	}
	// Print the final values of A and B
	fmt.Println(A, B)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var S string
	scanner.Scan()
	S = scanner.Text()
	var T string
	scanner.Scan()
	T = scanner.Text()
	A, _ := strconv.Atoi(scanner.Text())
	B, _ := strconv.Atoi(scanner.Text())
	var U string
	scanner.Scan()
	U = scanner.Text()
	solve(S, T, A, B, U)
}

// 