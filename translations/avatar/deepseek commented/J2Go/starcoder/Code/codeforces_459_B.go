package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read the size of the array
	N, _ := strconv.Atoi(readLine(reader))

	// Read the elements of the array
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(readLine(reader))
	}

	// Sort the array
	sort.Ints(A)

	// Find the minimum and maximum values in the array
	min := A[0]
	max := A[N-1]

	// Count the occurrences of the minimum and maximum values
	mins := 0
	maxs := 0
	for _, value := range A {
		if value == min {
			mins++
		}
		if value == max {
			maxs++
		}
	}

	// Special case: if min == max
	if min == max {
		fmt.Fprintln(writer, (max-min), " ", mins*(mins-1)/2)
	} else {
		// General case: if min!= max
		fmt.Fprintln(writer, (max-min), " ", mins*maxs)
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

// Debugging method to print debug statements
func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

