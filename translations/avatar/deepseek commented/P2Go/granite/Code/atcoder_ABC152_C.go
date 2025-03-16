

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take the number of elements as input
	N, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0:1])

	// Take a space-separated string of integers as input and convert them to a list of integers
	n := strings.Split(bufio.NewReader(os.Stdin).ReadLine()[0:N*2], " ")
	var a []int
	for _, x := range n {
		a = append(a, int(x[0:1]))
	}

	// Initialize a counter to 1 and a position index to 0
	a1 := 1
	pos := 0

	// Loop through the array from the second element to the last
	for i := 1; i < N; i++ {
		// Check if the current minimum element is greater than the current element
		if a[pos] > a[i] {
			// Increment the counter and update the position index
			a1 += 1
			pos = i
		}
	}

	// Print the final count of elements that are greater than the current minimum
	fmt.Println(a1)
}
