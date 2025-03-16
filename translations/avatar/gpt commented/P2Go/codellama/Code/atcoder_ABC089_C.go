
package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	// Read the number of strings to process
	var N int
	fmt.Scan(&N)

	// Read N strings from input
	S := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}

	// Define the target characters to count
	march := []string{"M", "A", "R", "C", "H"}

	// Initialize a list to count occurrences of each target character
	march_lis := make([]int, 5)

	// Count the occurrences of each character in the input strings
	for _, s := range S {
		if strings.ToUpper(s[:1]) == march[0] {
			march_lis[0]++
		} else if strings.ToUpper(s[:1]) == march[1] {
			march_lis[1]++
		} else if strings.ToUpper(s[:1]) == march[2] {
			march_lis[2]++
		} else if strings.ToUpper(s[:1]) == march[3] {
			march_lis[3]++
		} else if strings.ToUpper(s[:1]) == march[4] {
			march_lis[4]++
		}
	}

	// Initialize the answer variable to store the result
	ans := 0

	// Calculate the number of ways to choose 3 different characters from the counts
	for _, x := range march_lis {
		for _, y := range march_lis {
			for _, z := range march_lis {
				if x != y && x != z && y != z {
					ans += x * y * z
				}
			}
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

