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
	fmt.Println("Enter the number of elements in the list A:")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the elements of the list A:")
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	A = sort(A)
	i := 1
	ans := 0
	for i < N - 1 {
		if A[i-1] < A[i] > A[i+1] || A[i-1] > A[i] < A[i+1] {
			ans += 1
			i += 1
		} else {
			i += 1
		}
	}
	i += 1
	fmt.Println(ans + 1)
}

func sort(A []int) []int {
	for i := 0; i < len(A); i++ {
		for j := i + 1; j < len(A); j++ {
			if A[i] > A[j] {
				A[i], A[j] = A[j], A[i]
			}
		}
	}
	return A
}

