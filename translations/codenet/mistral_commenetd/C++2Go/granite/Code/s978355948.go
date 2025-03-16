

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize variables N and X with user input
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(read(reader))
	X, _ := strconv.Atoi(read(reader))

	// Create a slice L of size N to store the elements
	L := make([]int, N)

	// Read elements of slice L from user input
	for i := 0; i < N; i++ {
		L[i], _ = strconv.Atoi(read(reader))
	}

	// Initialize variable i and d to zero
	i := 0
	d := 0

	// Loop through the slice L until the sum d exceeds X
	for ; i < N && d <= X; i++ {
		// Add the current element of slice L to the sum d
		d += L[i]
	}

	// Print the index of the last element in the slice L that was added to the sum d
	fmt.Println(i + 1)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

