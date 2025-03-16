package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	soz, _ := reader.ReadString('\n')
	soz = soz[:len(soz)-1] // Remove the newline character

	// Initialize a list 'a' to store the cumulative count of consecutive characters
	// The length of 'a' is one more than the length of 'soz' to handle the base case
	a := make([]int, len(soz)+1)

	// Iterate through the string to fill the cumulative count array 'a'
	for i := 1; i < len(soz); i++ {
		// Carry forward the previous count
		a[i] = a[i-1]

		// If the current character is the same as the previous one, increment the count
		if soz[i-1] == soz[i] {
			a[i] += 1
		}
	}

	// Read the number of queries from the user
	n, _ := strconv.Atoi(readLine(reader))

	// Initialize an empty list to store the results of each query
	var arr []int

	// Process each query
	for i := 0; i < n; i++ {
		// Read the start and end indices for the query
		m, l := readLine(reader), readLine(reader)
		mInt, _ := strconv.Atoi(m)
		lInt, _ := strconv.Atoi(l)

		// Calculate the number of consecutive characters between indices m and l
		// and append the result to the 'arr' list
		arr = append(arr, a[lInt-1]-a[mInt-1])
	}

	// Print the results for each query
	for _, i := range arr {
		fmt.Println(i)
	}
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1] // Remove the newline character
}
