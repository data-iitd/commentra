package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from stdin
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of integers to be processed
	n, _ := strconv.Atoi(sc.Text())

	// Initialize an array to store the integers
	a := make([]int, n)

	// If there is only one integer, print it and exit
	if n == 1 {
		fmt.Println(a[0])
		return
	}

	// Read n integers from input and add them to the array
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sc.Text())
	}

	// Sort the array in ascending order
	sort.Ints(a)

	// If the largest number is 0, print 0 and exit
	if a[len(a)-1] == 0 {
		fmt.Println(0)
		return
	}

	// Initialize the answer variable
	ans := 0

	// Loop until the array is reduced to one element
	for {
		// If only one element remains, set it as the answer and break the loop
		if len(a) == 1 {
			ans = a[0]
			break
		}
		// Call the function to process the array and update it
		a = func(a)
	}

	// Print the final answer
	fmt.Println(ans)
}

// Function to process the array and return a modified version
func func(A []int) []int {
	// Create a copy of the input array
	a := A

	// Initialize a variable to store the minimum value
	min := 0

	// Iterate through the array
	for i := 0; i < len(a); i++ {
		// If the current element is 0, remove it from the list
		if a[i] == 0 {
			a = append(a[:i], a[i+1:]...)
			i-- // Adjust index after removal
		} else {
			// If min is not zero, update the current element
			if min!= 0 {
				a[i] = a[i] % min
				// If the updated element is 1, print 1 and exit
				if a[i] == 1 {
					fmt.Println(1)
					return a
				}
			} else {
				// Set min to the current element if min is still zero
				min = a[i]
			}
		}
	}

	// Sort the modified array before returning
	sort.Ints(a)
	return a
}

