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

	// Taking input for the number of elements
	fmt.Print("Enter the number of elements: ")
	NInput, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(NInput))

	// Taking input for the elements and converting them into a list of integers
	fmt.Print("Enter the elements separated by spaces: ")
	elementsInput, _ := reader.ReadString('\n')
	elementsStr := strings.Split(strings.TrimSpace(elementsInput), " ")
	elements := make([]int, N)
	for i := 0; i < N; i++ {
		elements[i], _ = strconv.Atoi(elementsStr[i])
	}

	// Initializing a counter 'a' to count the number of elements that are less than the current element
	a := 1

	// Initializing 'pos' to keep track of the position of the last element that was smaller
	pos := 0

	// Looping through the array starting from the second element
	for i := 1; i < N; i++ {
		// Checking if the current element is smaller than the element at 'pos'
		if elements[pos] > elements[i] {
			a += 1 // Incrementing the counter if the condition is met
			pos = i // Updating 'pos' to the current index
		}
	}

	// Printing the final count of elements that were smaller than the previous ones
	fmt.Println(a)
}
