package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Define constants and global variables
	const mod = 1e9 + 7
	march := []string{"M", "A", "R", "C", "H"}
	marchLis := make([]int, 5) // List to store the count of each marching order
	ans := 0                    // Variable to store the answer

	// Read input
	reader := bufio.NewReader(os.Stdin)
	var N int
	fmt.Fscan(reader, &N) // Number of inputs

	// Iterate through each string and increment the count of the corresponding marching order
	for i := 0; i < N; i++ {
		s, _ := reader.ReadString('\n')
		s = strings.TrimSpace(s)
		if len(s) > 0 {
			firstChar := strings.ToUpper(string(s[0]))
			for j, m := range march {
				if firstChar == m {
					marchLis[j]++
					break
				}
			}
		}
	}

	// Calculate the answer by finding the triple product of the counts of each marching order
	for i := 0; i < len(marchLis); i++ {
		for j := i + 1; j < len(marchLis); j++ {
			for k := j + 1; k < len(marchLis); k++ {
				ans += marchLis[i] * marchLis[j] * marchLis[k]
			}
		}
	}

	// Print the answer
	fmt.Println(ans)
}

// <END-OF-CODE>
