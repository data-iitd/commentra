package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func readInt() int {
	n, _ := strconv.Atoi(readLine())
	return n
}

func readMap() []int {
	line := readLine()
	parts := strings.Split(line, " ")
	intParts := make([]int, len(parts))
	for i, part := range parts {
		intPart, _ := strconv.Atoi(part)
		intParts[i] = intPart
	}
	return intParts
}

func readList() []int {
	line := readLine()
	parts := strings.Split(line, " ")
	intParts := make([]int, len(parts))
	for i, part := range parts {
		intPart, _ := strconv.Atoi(part)
		intParts[i] = intPart
	}
	return intParts
}

func zip(n int) [][]int {
	zipped := make([][]int, n)
	for i := 0; i < n; i++ {
		zipped[i] = readMap()
	}
	return zipped
}

func main() {
	// Set the recursion limit to a high value
	// (Go does not have a setrecursionlimit function, so we ignore this)

	// Define constants for infinity and modulo
	const INF = int(^uint(0) >> 1)
	const mod = 1000000007

	// Read the number of strings to process
	N := readInt()

	// Read N strings from input
	S := make([]string, N)
	for i := 0; i < N; i++ {
		S[i] = readLine()
	}

	// Define the target characters to count
	march := []string{"M", "A", "R", "C", "H"}

	// Initialize a list to count occurrences of each target character
	var march_lis [5]int

	// Count the occurrences of each character in the input strings
	for _, s := range S {
		firstChar := strings.ToUpper(string(s[0]))
		for j, m := range march {
			if firstChar == m {
				march_lis[j]++
				break
			}
		}
	}

	// Initialize the answer variable to store the result
	var ans int

	// Calculate the number of ways to choose 3 different characters from the counts
	for _, x := range march_lis {
		for _, y := range march_lis {
			for _, z := range march_lis {
				if x != 0 && y != 0 && z != 0 {
					ans += x * y * z
				}
			}
		}
	}

	// Print the final answer
	fmt.Println(ans)
}
