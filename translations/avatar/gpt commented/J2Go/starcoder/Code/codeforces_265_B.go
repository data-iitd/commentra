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
	input = strings.Replace(input, "\n", "", -1)
	n, _ := strconv.Atoi(input)

	// Initialize an array to hold the input integers
	arr := make([]int, n)

	// Populate the array with integers from user input
	for i := 0; i < n; i++ {
		fmt.Print("Enter the ", i+1, "th element: ")
		input, _ := reader.ReadString('\n')
		input = strings.Replace(input, "\n", "", -1)
		arr[i], _ = strconv.Atoi(input)
	}

	// Initialize the answer with the first element of the array plus one
	ans := arr[0] + 1

	// Calculate the total distance based on the differences between consecutive elements
	for i := 1; i < n; i++ {
		// Add the absolute difference between the current and previous element, plus 2
		ans += abs(arr[i] - arr[i-1]) + 2
	}

	// Output the final calculated answer
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

