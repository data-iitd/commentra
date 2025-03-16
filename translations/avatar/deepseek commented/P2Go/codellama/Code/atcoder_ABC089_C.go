
package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	// Read the number of strings
	var N int
	fmt.Scan(&N)

	// Read the list of strings
	S := make([]string, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&S[i])
	}

	// List of characters that can be selected
	march := []string{"M", "A", "R", "C", "H"}

	// Initialize a list to count occurrences of each character in 'march'
	march_lis := make([]int, 5)

	// Count the occurrences of characters in 'march' in the list of strings
	for _, s := range S {
		if strings.Contains(s, march[0]) {
			march_lis[0]++
		}
		if strings.Contains(s, march[1]) {
			march_lis[1]++
		}
		if strings.Contains(s, march[2]) {
			march_lis[2]++
		}
		if strings.Contains(s, march[3]) {
			march_lis[3]++
		}
		if strings.Contains(s, march[4]) {
			march_lis[4]++
		}
	}

	// Initialize the answer variable
	ans := 0

	// Calculate the number of combinations of three elements from march_lis
	for _, x := range march_lis {
		for _, y := range march_lis {
			for _, z := range march_lis {
				ans += x * y * z
			}
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

