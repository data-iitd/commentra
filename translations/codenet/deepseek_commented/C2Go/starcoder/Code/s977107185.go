<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		i, j, N, tmp, count int
		A                   [100]int
	)

	reader := bufio.NewReader(os.Stdin)
	N, _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))

	for i = 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Implement Bubble Sort
<<<<<<< HEAD
	for i = 0; i < N - 1; i++ {
		for j = N - 1; j > i; j-- {
			if A[j] < A[j - 1] {
				tmp = A[j] // Swap A[j] and A[j-1]
				A[j] = A[j - 1]
				A[j - 1] = tmp
=======
	for i = 0; i < N-1; i++ {
		for j = N - 1; j > i; j-- {
			if A[j] < A[j-1] {
				tmp = A[j] // Swap A[j] and A[j-1]
				A[j] = A[j-1]
				A[j-1] = tmp
>>>>>>> 98c87cb78a (data updated)
				count++ // Increment the swap counter
			}
		}
	}

	for i = 0; i < N; i++ {
		fmt.Printf("%d", A[i]) // Print the sorted array elements
		if i < N-1 {
			fmt.Printf(" ") // Print a space between elements, but not after the last element
		}
	}

	fmt.Printf("\n") // Print a newline character to end the line

	fmt.Printf("%d\n", count) // Print the number of swaps
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

