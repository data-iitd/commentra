package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the array
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements in the array: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Initialize an array to hold the integers and a variable to store the sum
	arr := make([]int, n)
	sum := 0

	// Read the integers into the array and calculate the sum
	for i := 0; i < n; i++ {
		fmt.Printf("Enter the %d element: ", i+1)
		input, _ := reader.ReadString('\n')
		arr[i], _ = strconv.Atoi(strings.TrimSpace(input))
		sum += arr[i] // Accumulate the sum of the elements
	}

	// Initialize a counter for valid indices and a StringBuilder for output
	c := 0
	sb := strings.Builder{}

	// Check each element to see if it can be the "removed" element
	for i := 0; i < n; i++ {
		// Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++ // Increment the count of valid indices
			sb.WriteString(fmt.Sprintf("%d ", i+1)) // Append the 1-based index to the StringBuilder
		}
	}

	// Output the count of valid indices
	fmt.Println(c)

	// Output the indices of valid elements
	fmt.Println(sb.String())
}

