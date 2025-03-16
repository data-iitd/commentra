
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Taking input for the number of elements
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements: ")
	N, _ := strconv.Atoi(reader.ReadLine()[0])

	// Taking input for the elements and converting them into a slice of integers
	fmt.Print("Enter the elements separated by spaces: ")
	input, _ := reader.ReadString('\n')
	n := make([]int, N)
	for i, v := range strings.Split(input, " ") {
		n[i], _ = strconv.Atoi(v)
	}

	// Initializing a counter 'a' to count the number of elements that are less than the current element
	a := 1

	// Initializing 'pos' to keep track of the position of the last element that was smaller
	pos := 0

	// Looping through the slice starting from the second element
	for i := 1; i < N; i++ {
		// Checking if the current element is smaller than the element at 'pos'
		if n[pos] > n[i] {
			a++ // Incrementing the counter if the condition is met
			pos = i // Updating 'pos' to the current index
		}
	}

	// Printing the final count of elements that were smaller than the previous ones
	fmt.Println(a)
}

