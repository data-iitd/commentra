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
	
	// Read the number of rounds (n) and the number of George's complexities (m)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	
	// Read the complexities for each round into a slice
	roundComplexity := make([]int, n)
	input, _ = reader.ReadString('\n')
	parts = strings.Split(strings.TrimSpace(input), " ")
	for i := 0; i < n; i++ {
		roundComplexity[i], _ = strconv.Atoi(parts[i])
	}
	
	// Read George's complexities into another slice
	georgeComplexity := make([]int, m)
	input, _ = reader.ReadString('\n')
	parts = strings.Split(strings.TrimSpace(input), " ")
	for i := 0; i < m; i++ {
		georgeComplexity[i], _ = strconv.Atoi(parts[i])
	}
	
	// Initialize indices for both slices
	i, j := 0, 0
	
	// Iterate through both slices to compare complexities
	for i < n && j < m {
		if roundComplexity[i] <= georgeComplexity[j] {
			i++
		}
		j++
	}
	
	// Output the number of rounds that George cannot handle
	fmt.Println(n - i)
}
