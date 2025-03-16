
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

	// Take the first line of input which are two integers 'num' and 'k'
	firstLine, _ := reader.ReadString('\n')
	firstLine = strings.TrimSpace(firstLine)
	split := strings.Split(firstLine, " ")
	num, _ := strconv.Atoi(split[0])
	k, _ := strconv.Atoi(split[1])

	// Comment: Initialize 'num' and 'k' with the values from user input

	// Take the second line of input which is a list 'arr' of integers
	secondLine, _ := reader.ReadString('\n')
	secondLine = strings.TrimSpace(secondLine)
	split = strings.Split(secondLine, " ")
	arr := make([]int, num)
	for i := 0; i < num; i++ {
		arr[i], _ = strconv.Atoi(split[i])
	}

	// Comment: Initialize an empty list 'arr' to store the input integers

	// Create an empty set 'different' to store unique integers
	different := make(map[int]bool)

	// Comment: Initialize an empty set 'different' to store unique integers

	// Sort the list 'arr' in ascending order
	for i := 0; i < num; i++ {
		for j := i + 1; j < num; j++ {
			if arr[i] > arr[j] {
				arr[i], arr[j] = arr[j], arr[i]
			}
		}
	}

	// Comment: Sort the list 'arr' in ascending order for easier comparison

	// Iterate through each integer 'x' in the sorted list 'arr'
	temp := 0
	for i := 0; i < num; i++ {
		x := arr[i]

		// Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
		if x%k!= 0 ||!different[x/k] {

			// If the condition is true, add 'x' to the set 'different'
			different[x] = true

			// Comment: If 'x' is not divisible by 'k' or its quotient is not already in 'different', add it to 'different'

			// Update the maximum length of 'different' seen so far
			if len(different) > temp {
				temp = len(different)
			}
		}
	}

	// Comment: After the loop, 'temp' stores the maximum length of 'different' seen during the iteration

	// Print the maximum length of 'different'
	fmt.Println(temp)

	// Comment: Finally, print the maximum length of 'different'
}

