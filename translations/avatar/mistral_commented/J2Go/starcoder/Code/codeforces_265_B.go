package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the first line of input from stdin and save it to a variable
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')

	// Convert the input string to a slice of integers using the Split method
	// on the string and the strconv.Atoi function
	inputSlice := strings.Split(input, " ")
	inputSliceInt := make([]int, len(inputSlice))
	for i, val := range inputSlice {
		inputSliceInt[i], _ = strconv.Atoi(val)
	}

	// Save the first element of the input slice to a variable
	n := inputSliceInt[0]

	// Create a slice of integers of size n
	arr := make([]int, n)

	// Use a for loop to read n integers from the standard input and store them in the array arr
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(inputSlice[i+1])
	}

	// Initialize a variable ans with the first element of the array and add 1 to it
	ans := arr[0] + 1

	// Use another for loop to iterate through the remaining elements of the array arr
	for i := 1; i < n; i++ {
		// Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
		ans += abs(arr[i] - arr[i-1]) + 2
	}

	// Finally, print the value of ans to the standard output
	fmt.Println(ans)
}

