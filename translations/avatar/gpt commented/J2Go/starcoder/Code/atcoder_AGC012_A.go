package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the size of the array")
	// Reading the size of the array
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	// Initializing an array of size 3*n to hold the input values
	array := make([]int, 3*n)
	fmt.Println("Enter the elements of the array")
	// Filling the array with user input values
	for i := 0; i < len(array); i++ {
		array[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	// Sorting the array in ascending order
	sort.Ints(array)
	// Setting the head pointer to the second last element of the sorted array
	head := len(array) - 2
	// Initializing a variable to accumulate the result
	res := 0
	// Looping n times to sum up the required elements from the sorted array
	for i := 0; i < n; i++ {
		res += array[head] // Adding the current element pointed by head to the result
		head -= 2          // Moving the head pointer two positions to the left for the next iteration
	}
	// Printing the final result
	fmt.Println(res)
}

