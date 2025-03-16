
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements in the array: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Read the size of the subarray to be summed
	fmt.Print("Enter the size of the subarray to be summed: ")
	input, _ = reader.ReadString('\n')
	a, _ := strconv.Atoi(strings.TrimSpace(input))

	// Declare and initialize variables
	var sum int = 0
	s := make([]int, n)

	// Read the elements of the array from the user
	for i := 0; i < n; i++ {
		fmt.Printf("Enter the %d-th element of the array: ", i+1)
		input, _ = reader.ReadString('\n')
		s[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}

	// Sort the array in ascending order
	sort.Ints(s)

	// Calculate the sum of the last 'a' elements of the sorted array
	for i := n - 1; i > n-a-1; i-- {
		sum += s[i]
	}

	// Print the result
	fmt.Printf("The sum of the last %d elements of the sorted array is %d.\n", a, sum)
}

