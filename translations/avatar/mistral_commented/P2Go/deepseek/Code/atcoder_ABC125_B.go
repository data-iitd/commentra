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

	// Read the number of test cases
	N, _ := strconv.Atoi(readLine(reader))

	// Read the array V of size N
	V := readArray(reader)

	// Read the array C of size N
	C := readArray(reader)

	// Initialize an empty list to store the differences between V and C
	var list []int

	// Initialize variables to store the current difference and the sum of differences
	var ans int
	var X, Y int

	// Iterate through each index i from 0 to N-1
	for i := 0; i < N; i++ {
		// If the difference between V[i] and C[i] is positive
		if V[i] - C[i] > 0 {
			// Update X and Y with the respective values from V and C at index i
			X = V[i]
			Y = C[i]
			// Append the difference X-Y to the list
			list = append(list, X - Y)
			// Update the sum of differences
			ans += X - Y
		}
	}

	// Print the sum of all the elements in the list
	fmt.Println(sum(list))
	// Print the sum of all the differences between V and C
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	return line
}

func readArray(reader *bufio.Reader) []int {
	line := readLine(reader)
	elements := strings.Split(line, " ")
	intElements := make([]int, len(elements))
	for i, elem := range elements {
		intElements[i], _ = strconv.Atoi(elem)
	}
	return intElements
}

func sum(arr []int) int {
	total := 0
	for _, num := range arr {
		total += num
	}
	return total
}
