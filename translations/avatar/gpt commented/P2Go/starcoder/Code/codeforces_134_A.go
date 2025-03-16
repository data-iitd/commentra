package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(readLine())

	// Read the list of integers
	w := strings.Split(readLine(), " ")
	w = w[:n]
	for i := 0; i < len(w); i++ {
		w[i], _ = strconv.Atoi(w[i])
	}

	// Calculate the sum of the list
	x := 0
	for i := 0; i < len(w); i++ {
		x += w[i]
	}

	// Initialize an empty list to store indices
	d := []int{}

	// Iterate through each element in the list
	for i := 0; i < len(w); i++ {
		// Check if removing the current element results in an average equal to the current element
		if (x - w[i])/(n-1) == w[i] {
			// If the condition is met, append the 1-based index to the list
			d = append(d, i+1)
		}
	}

	// Print the number of valid indices found
	fmt.Println(len(d))

	// Print the valid indices as a space-separated string
	fmt.Println(strings.Trim(strings.Join(strings.Fields(fmt.Sprint(d)), " "), "[]"))
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	line, _, _ := buf.ReadLine()
	return string(line)
}

