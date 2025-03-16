
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a Scanner object to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the array
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize an array to hold the integers and a variable to store the sum
	arr := make([]int, n)
	sum := 0

	// Read the integers into the array and calculate the sum
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
		sum += arr[i] // Accumulate the sum of the elements
	}

	// Initialize a counter for valid indices and a StringBuilder for output
	c := 0
	var sb strings.Builder

	// Check each element to see if it can be the "removed" element
	for i := 0; i < n; i++ {
		// Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++ // Increment the count of valid indices
			sb.WriteString(strconv.Itoa(i + 1) + " ") // Append the 1-based index to the StringBuilder
		}
	}

	// Output the count of valid indices
	fmt.Println(c)

	// Output the indices of valid elements
	fmt.Println(sb.String())
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

