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

	// Initialize an array to hold the input values
	arr := make([]int, n)

	// Loop to read 'n' integers from the user and store them in the array
	for i := 0; i < n; i++ {
		fmt.Print("Enter the ", i+1, "th element: ")
		input, _ := reader.ReadString('\n')
		arr[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}

	// Initialize the answer with the absolute value of the first element
	answer := arr[0]

	// Loop to calculate the sum of absolute differences between consecutive elements
	for i := 1; i < n; i++ {
		answer += int(math.Abs(float64(arr[i] - arr[i-1])))
	}

	// Output the final calculated answer
	fmt.Println(answer)
}

