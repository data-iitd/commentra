package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Set up input and output streams
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read four integers from input
	input, _ := reader.ReadString('\n')
	numbers := strings.Fields(input)
	a, _ := strconv.Atoi(numbers[0])
	b, _ := strconv.Atoi(numbers[1])
	c, _ := strconv.Atoi(numbers[2])
	d, _ := strconv.Atoi(numbers[3])

	// Check conditions to determine the output
	if c > b {
		// If c is greater than b, output 0
		fmt.Fprintln(writer, 0)
	} else if a > d {
		// If a is greater than d, output 0
		fmt.Fprintln(writer, 0)
	} else if a < c {
		// If a is less than c, calculate and output the difference
		fmt.Fprintln(writer, min(b, d)-c)
	} else {
		// Create a list to hold the four integers
		nums := []int{a, b, c, d}

		// Sort the list to find the second largest and third largest values
		sort.Ints(nums)

		// Output the difference between the second largest and third largest values
		fmt.Fprintln(writer, nums[2]-nums[1])
	}
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

