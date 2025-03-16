package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of strings
	var N int
	fmt.Fscan(reader, &N)

	// Read the list of strings
	S := make([]string, N)
	for i := 0; i < N; i++ {
		S[i], _ = reader.ReadString('\n')
		S[i] = strings.TrimSpace(S[i])
	}

	// List of characters that can be selected
	march := []string{"M", "A", "R", "C", "H"}

	// Initialize a slice to count occurrences of each character in 'march'
	marchCount := make([]int, 5)

	// Count the occurrences of characters in 'march' in the list of strings
	for _, s := range S {
		firstChar := strings.ToUpper(string(s[0]))
		for i, char := range march {
			if firstChar == char {
				marchCount[i]++
			}
		}
	}

	// Initialize the answer variable
	ans := 0

	// Calculate the number of combinations of three elements from marchCount
	for i := 0; i < 5; i++ {
		for j := i + 1; j < 5; j++ {
			for k := j + 1; k < 5; k++ {
				ans += marchCount[i] * marchCount[j] * marchCount[k]
			}
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
