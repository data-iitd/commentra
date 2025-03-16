package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Read the number of elements from input
	N, _ := strconv.Atoi(readLine(reader))
	// Initialize an array to hold the input integers
	A := make([]int, N)
	// Read N integers from input and store them in the array A
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(readLine(reader))
	}
	// Sort the array A to easily find the minimum and maximum values
	sort.Ints(A)
	// Identify the minimum and maximum values in the sorted array
	min := A[0]
	max := A[N-1]
	// Initialize counters for occurrences of min and max values
	mins := 0
	maxs := 0
	// Count how many times the minimum and maximum values occur in the array
	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}
	// If all elements are the same (min equals max)
	if min == max {
		// Calculate the difference (which is 0) and the number of ways to choose 2 from mins
		fmt.Println((max - min), mins*(mins-1)/2)
	} else {
		// Calculate the difference and the product of occurrences of min and max
		fmt.Println((max - min), mins*maxs)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

