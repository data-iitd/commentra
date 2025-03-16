package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func input() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	line := input()
	N, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	A := strings.Split(strings.TrimSpace(line), " ")
	for i := range A {
		A[i], _ = strconv.Atoi(A[i])
	}

	// Remove consecutive duplicates
	A = removeDuplicates(A)
	N = len(A)

	ans := 0
	for i := 1; i < N-1; i++ {
		if (A[i-1] < A[i] && A[i] > A[i+1]) || (A[i-1] > A[i] && A[i] < A[i+1]) {
			ans++
			i++
		}
	}
	fmt.Println(ans + 1)
}

func removeDuplicates(arr []int) []int {
	unique := []int{}
	for i := 0; i < len(arr); i++ {
		if i == 0 || arr[i] != arr[i-1] {
			unique = append(unique, arr[i])
		}
	}
	return unique
}

