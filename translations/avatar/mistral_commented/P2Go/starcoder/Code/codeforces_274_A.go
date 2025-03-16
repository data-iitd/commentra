
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
	// Take the first line of input which are two integers 'num' and 'k'
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	num, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	k, _ := strconv.Atoi(line)

	// Comment: Initialize 'num' and 'k' with the values from user input

	// Take the second line of input which is a list 'arr' of integers
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	arr := strings.Split(line, " ")
	arr = arr[:len(arr)-1]
	for i := 0; i < len(arr); i++ {
		arr[i], _ = strconv.Atoi(arr[i])
	}

	// Comment: Initialize an empty list 'arr' to store the input integers

	// Create an empty set 'different' to store unique integers
	different := make(map[int]bool)

	// Comment: Initialize an empty set 'different' to store unique integers

	// Sort the list 'arr' in ascending order
	sort.Ints(arr)

	// Comment: Sort the list 'arr' in ascending order for easier comparison

	// Iterate through each integer 'x' in the sorted list 'arr'
	for _, x := range arr {

		// Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
		if (x%k!= 0 ||!different[x/k]) {

			// If the condition is true, add 'x' to the set 'different'
			different[x] = true

			// Comment: If 'x' is not divisible by 'k' or its quotient is not already in 'different', add it to 'different'

		}

	}

	// Comment: After the loop, 'different' stores the unique integers seen during the iteration

	// Print the maximum length of 'different'
	fmt.Println(len(different))

	// Comment: Finally, print the maximum length of 'different'

}

