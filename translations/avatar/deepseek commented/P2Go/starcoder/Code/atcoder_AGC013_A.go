package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading number of elements
	N := readInt()
	// Reading list of elements
	A := readArray(N)

	// Removing consecutive duplicates from list A
	A = removeConsecutiveDuplicates(A)
	// Updating N to reflect the new length of A
	N = len(A)

	// Initializing variables for main logic
	i := 1
	ans := 0

	// Main logic to find peaks
	for i < N-1 {
		if A[i-1] < A[i] && A[i] > A[i+1] || A[i-1] > A[i] && A[i] < A[i+1] {
			ans += 1
			i += 1 // Skip next element as it's already checked
		}
		i += 1
	}

	// Output the total number of peaks found
	fmt.Println(ans + 1)
}

// Function to read input line
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Function to read an integer input
func readInt() int {
	val, _ := strconv.Atoi(readLine())
	return val
}

// Function to read an array of integers
func readArray(size int) []int {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = readInt()
	}
	return arr
}

// Function to remove consecutive duplicates from list A
func removeConsecutiveDuplicates(A []int) []int {
	var ans []int
	for _, v := range A {
		if len(ans) == 0 || ans[len(ans)-1]!= v {
			ans = append(ans, v)
		}
	}
	return ans
}

