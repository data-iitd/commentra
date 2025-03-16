package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	A := readInts()

	// Removing consecutive duplicates from list A
	uniqueA := []int{}
	for i := 0; i < len(A); i++ {
		if i == 0 || A[i] != A[i-1] {
			uniqueA = append(uniqueA, A[i])
		}
	}
	N = len(uniqueA)

	// Initializing variables for main logic
	i := 1
	ans := 0

	// Main logic to find peaks
	for i < N-1 {
		if uniqueA[i-1] < uniqueA[i] && uniqueA[i] > uniqueA[i+1] || uniqueA[i-1] > uniqueA[i] && uniqueA[i] < uniqueA[i+1] {
			ans += 1
			i += 1 // Skip next element as it's already checked
		}
		i += 1
	}

	// Output the total number of peaks found
	fmt.Println(ans + 1)
}
