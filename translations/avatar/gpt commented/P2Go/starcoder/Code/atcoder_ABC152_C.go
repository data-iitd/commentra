package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements: ")
	// Taking input for the number of elements
	N, _ := strconv.Atoi(reader.ReadString('\n'))

	fmt.Println("Enter the elements separated by spaces: ")
	// Taking input for the elements and converting them into a list of integers
	n := strings.Split(reader.ReadString('\n'), " ")
	// Converting the list of integers into a NumPy array for easier manipulation
	n = make([]int, len(n))
	for i := 0; i < len(n); i++ {
		n[i], _ = strconv.Atoi(n[i])
	}

	// Initializing a counter 'a' to count the number of elements that are less than the current element
	a := 1
	// Initializing 'pos' to keep track of the position of the last element that was smaller
	pos := 0
	// Looping through the array starting from the second element
	for i := 1; i < N; i++ {
		// Checking if the current element is smaller than the element at 'pos'
		if n[pos] > n[i] {
			a++  // Incrementing the counter if the condition is met
			pos = i  // Updating 'pos' to the current index
	}

	// Printing the final count of elements that were smaller than the previous ones
	fmt.Println(a)
}

