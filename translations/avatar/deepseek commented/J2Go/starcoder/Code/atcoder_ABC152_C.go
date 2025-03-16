
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
	fmt.Println(solve())
}

func solve() int {
	// Read the integer N from the input
	N, _ := strconv.Atoi(readLine(reader))

	// Initialize an array of size N to store the integers
	arr := make([]int, N)

	// Read N integers from the input and store them in the array
	for i := 0; i < N; i++ {
		arr[i], _ = strconv.Atoi(readLine(reader))
	}

	// Initialize a sum variable to 0
	sum := 0

	// Create a priority queue to store the integers in ascending order
	q := make([]int, 0)

	// Iterate through the array and add each element to the priority queue
	for i := 0; i < N; i++ {
		q = append(q, arr[i])

		// Check if the current element is less than or equal to the smallest element in the priority queue
		if arr[i] <= q[0] {
			sum++
		}
	}

	// Return the sum
	return sum
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

