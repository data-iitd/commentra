package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Create a buffered reader for input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of strings to process
	var N int
	fmt.Fscan(reader, &N)

	// Read N strings from input
	S := make([]string, N)
	for i := 0; i < N; i++ {
		S[i], _ = reader.ReadString('\n')
		S[i] = strings.TrimSpace(S[i])
	}

	// Define the target characters to count
	march := []string{"M", "A", "R", "C", "H"}

	// Initialize a slice to count occurrences of each target character
	marchCount := make([]int, 5)

	// Count the occurrences of each character in the input strings
	for _, s := range S {
		firstChar := strings.ToUpper(string(s[0]))
		for i, char := range march {
			if firstChar == char {
				marchCount[i]++
				break
			}
		}
	}

	// Initialize the answer variable to store the result
	ans := 0

	// Calculate the number of ways to choose 3 different characters from the counts
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
