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

	// Read the number of elements in the list 'A'
	N, _ := strconv.Atoi(readLine(reader))

	// Initialize an empty list 'A' with the given size 'N'
	// and read the elements from the standard input
	A := readInts(reader)

	// Initialize minimum and maximum indices 'mn' and 'mx'
	mn, mx := N+1, -1

	// Iterate through the list 'A' from index 0 to 'N-1'
	for i := 0; i < N; i++ {
		// Check if the current index 'i' is not equal to the next element
		if i+1 != A[i] {
			// Update the minimum and maximum indices 'mn' and 'mx'
			if mn > i {
				mn = i
			}
			if mx < i {
				mx = i
			}
		}
	}

	// Check if the maximum index 'mx' is still equal to -1
	if mx == -1 {
		// If yes, print '0 0' as the output
		fmt.Println("0 0")
	} else {
		// Slice the list 'A' based on the indices 'mn' and 'mx+1'
		A = append(A[:mn], append(A[mn:(mx+1)], A[(mx+1):]...)...)

		// Check if the sliced list 'A' is sorted in ascending order
		sortedA := make([]int, len(A))
		copy(sortedA, A)
		sort.Ints(sortedA)
		if reflect.DeepEqual(A, sortedA) {
			// If yes, print the minimum and maximum indices 'mn+1' and 'mx+1' as the output
			fmt.Println(mn+1, mx+1)
		} else {
			// If no, print '0 0' as the output
			fmt.Println("0 0")
		}
	}
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

func readInts(reader *bufio.Reader) []int {
	line := readLine(reader)
	ints := []int{}
	for _, s := range strings.Split(line, " ") {
		num, _ := strconv.Atoi(s)
		ints = append(ints, num)
	}
	return ints
}

