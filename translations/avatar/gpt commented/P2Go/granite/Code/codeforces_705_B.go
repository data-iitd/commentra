
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Use bufio for faster input reading
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	n, _ := strconv.Atoi(read(reader))

	// Read the list of integers from input
	w := readSlice(reader, n)

	// Initialize a variable 'c' to track the output state
	c := 2

	// Iterate through each element in the list 'w'
	for _, i := range w {
		// If the current element is 1, print the current value of 'c'
		if i == 1 {
			fmt.Println(c)
		}
		// If the current element is even, toggle 'c' between 2 and 3
		else if i%2 == 0 {
			c = 3 - c // This will switch c between 2 and 3
			fmt.Println(c)
		}
		// If the current element is odd (and not 1), print the current value of 'c'
		else {
			fmt.Println(c)
		}
	}
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

func readSlice(reader *bufio.Reader, n int) []int {
	slice := make([]int, n)
	for i := 0; i < n; i++ {
		str, _, _ := reader.ReadLine()
		num, _ := strconv.Atoi(string(str))
		slice[i] = num
	}
	return slice
}

