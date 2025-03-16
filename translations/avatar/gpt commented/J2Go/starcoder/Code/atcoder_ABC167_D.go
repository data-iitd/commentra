package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Constants for modulo and limits
const (
	MOD = 1000000007
	MAX = int(^uint(0) >> 1)
	LMAX = int64(^uint64(0) >> 1)
)

// Length for the array
var len = 1000001

func main() {
	// Read the number of elements N and the long value K
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	K, _ := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)

	// Initialize the array A to store the input values
	A := make([]int, N)

	// Read N integers into the array A and adjust values to be zero-indexed
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		A[i] -= 1
	}

	// Set to track used indices and arrays to store index and position
	used := make(map[int]bool)
	idx := make([]int, N)
	pos := make([]int, N)

	// Initialize variables for the cycle detection
	next := 0
	cur := 0

	// Detect the cycle in the array using the 'used' set
	for!used[next] {
		used[next] = true
		idx[next] = cur
		pos[cur] = next
		next = A[next]
		cur++
	}

	// Calculate the lengths of the cycle and the position of the next element
	a := int64(cur - idx[next])
	b := int64(idx[next])

	// Calculate the answer based on the cycle length and K
	ans := (10000*a + K - b) % a + b

	// If b is greater than K, set ans to K
	if b > K {
		ans = K
	}

	// Output the result, adjusting for 1-based indexing
	fmt.Println(pos[ans] + 1)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

