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
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	N, _ := strconv.Atoi(line)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		A[i], _ = strconv.Atoi(line)
	}

	// Remove consecutive duplicates
	A = removeDuplicates(A)
	N = len(A)

	// Initialize variables
	i := 1
	ans := 0

	// Main logic
	for i < N-1 {
		if A[i-1] < A[i] && A[i] > A[i+1] || A[i-1] > A[i] && A[i] < A[i+1] {
			ans++
			i++
		}
		i++
	}

	fmt.Println(ans + 1)
}

func removeDuplicates(A []int) []int {
	if len(A) == 0 {
		return A
	}

	result := []int{A[0]}
	for i := 1; i < len(A); i++ {
		if A[i] != A[i-1] {
			result = append(result, A[i])
		}
	}
	return result
}

