
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the array
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.Atoi(strings.TrimSpace(nTemp))
	checkError(err)

	// Initialize the array to store cumulative sums
	arr := make([]int, n)

	// Read the first element and assign it to the first index of the array
	arr[0], err = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	checkError(err)

	// Populate the array with cumulative sums
	for i := 1; i < n; i++ {
		// Read the next integer and add it to the previous cumulative sum
		xTemp, err := reader.ReadString('\n')
		checkError(err)
		x, err := strconv.Atoi(strings.TrimSpace(xTemp))
		checkError(err)
		arr[i] = x + arr[i-1]
	}

	// Read the number of queries
	mTemp, err := reader.ReadString('\n')
	checkError(err)
	m, err := strconv.Atoi(strings.TrimSpace(mTemp))
	checkError(err)

	// Initialize the array to store the queries
	q := make([]int, m)

	// Read each query into the array
	for i := 0; i < m; i++ {
		qTemp, err := reader.ReadString('\n')
		checkError(err)
		q[i], err = strconv.Atoi(strings.TrimSpace(qTemp))
		checkError(err)
	}

	// Process each query and print the result
	for k := 0; k < m; k++ {
		fmt.Println(fun(arr, q[k], n, m) + 1)
	}
}

// Function to perform binary search on the cumulative sum array
func fun(arr []int, q int, n int, m int) int {
	res := 0 // Variable to store the result index
	i := 0
	j := n

	// Perform binary search to find the appropriate index
	for i <= j {
		md := i + (j-i)/2 // Calculate the mid index

		// If the middle element is equal to the query, return the index
		if arr[md] == q {
			return md
		}
		// If the middle element is greater than the query, adjust the search range
		else if arr[md] > q {
			res = md // Update result to the current mid index
			j = md - 1 // Move the end pointer left
		} else {
			i = md + 1 // Move the start pointer right
		}
	}

	// Return the last found index where the cumulative sum is less than the query
	return res
}

// Function to read a single line from the console
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

// Function to check for errors and exit the program if an error is found
func checkError(err error) {
	if err!= nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
}

// END-OF-CODE