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

	// Read the number of strings
	N, _ := strconv.Atoi(readLine(reader))

	// Read the list of strings
	S := make([]string, N)
	for i := 0; i < N; i++ {
		S[i] = readLine(reader)
	}

	// List of characters that can be selected
	march := []string{"M", "A", "R", "C", "H"}

	// Initialize a list to count occurrences of each character in 'march'
	march_lis := make([]int, 5)

	// Count the occurrences of characters in 'march' in the list of strings
	for _, s := range S {
		for j, m := range march {
			if strings.HasPrefix(s, m) {
				march_lis[j]++
				break
			}
		}
	}

	// Initialize the answer variable
	ans := 0

	// Calculate the number of combinations of three elements from march_lis
	for i := 0; i < 3; i++ {
		for j := i + 1; j < 4; j++ {
			for k := j + 1; k < 5; k++ {
				ans += march_lis[i] * march_lis[j] * march_lis[k]
			}
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}
