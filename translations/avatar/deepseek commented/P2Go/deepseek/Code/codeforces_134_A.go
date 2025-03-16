package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the list `w`
	n, _ := strconv.Atoi(readLine(reader))

	// Read `n` integers from the standard input and store them in the list `w`
	w := readInts(reader)

	// Calculate the sum of all elements in the list `w`
	x := 0
	for _, value := range w {
		x += value
	}

	// Initialize an empty list `d` to store the indices of elements that satisfy the condition
	d := []int{}

	// Iterate over each element in the list `w`
	for i := 0; i < n; i++ {
		// Check if the current element `w[i]` is equal to the average of the total sum `x` and the number of elements `n` minus one
		if (x - w[i]) / (n - 1) == w[i] {
			// Append the 1-based index of the element to the list `d`
			d = append(d, i + 1)
		}
	}

	// Print the length of the list `d`
	fmt.Println(len(d))

	// Print the indices in `d` separated by spaces
	fmt.Println(strings.Trim(fmt.Sprint(d), "[]"))
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

func readInts(reader *bufio.Reader) []int {
	line := readLine(reader)
	ints := []int{}
	for _, s := range strings.Split(line, " ") {
		num, _ := strconv.Atoi(s)
		ints = append(ints, num)
	}
	return ints
}

