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

	// Convert the input string to a slice of integers using the Split function
	inputSlice := strings.Split(input, " ")

	// Convert the slice of strings to a slice of integers using the Sprintf function
	inputSliceInt := make([]int, len(inputSlice))
	for i := 0; i < len(inputSlice); i++ {
		inputSliceInt[i], _ = strconv.Atoi(inputSlice[i])
	}

	// Initialize the variable `answer` with the absolute value of the first element of the array `arr`
	answer := inputSliceInt[0]

	// Use a for loop to iterate over the remaining elements of the array `arr` and calculate the absolute difference between each element and the previous one, adding the result to the variable `answer`
	for i := 1; i < len(inputSliceInt); i++ {
		answer += int(math.Abs(float64(inputSliceInt[i] - inputSliceInt[i-1])))
	}

	// Print the value of the variable `answer` to the standard output stream
	fmt.Println(answer)
}

