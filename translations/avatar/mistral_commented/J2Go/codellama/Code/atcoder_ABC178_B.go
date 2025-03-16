
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declaring and initializing a FastReader object for reading input
	in := bufio.NewReader(os.Stdin)

	// Declaring and initializing an array of long integers named a with size 4
	a := make([]int64, 4)

	// Iterating through the elements of the array a
	for i := 0; i < 4; i++ {
		// Reading the next long integer from the input and storing it in the current element of the array
		a[i], _ = strconv.ParseInt(strings.TrimSpace(in.ReadString()), 10, 64)
	}

	// Calculating the maximum product of pairs of elements in the array a
	result := int64(0)
	if a[0]*a[2] > result {
		result = a[0] * a[2]
	}
	if a[1]*a[3] > result {
		result = a[1] * a[3]
	}
	if a[0]*a[3] > result {
		result = a[0] * a[3]
	}
	if a[1]*a[2] > result {
		result = a[1] * a[2]
	}

	// Printing the result to the standard output
	fmt.Println(result)
}

