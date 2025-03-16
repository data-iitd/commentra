
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables
	var key, i, j, len int
	var a []int

	// Read the length of the array from the user
	fmt.Print("Enter the length of the array: ")
	fmt.Scanln(&len)

	// Read the elements of the array from the user
	fmt.Print("Enter ", len, " integers: ")
	scanner := bufio.NewScanner(os.Stdin)
	for i = 0; i < len; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		a = append(a, num)
	}

	// Sort the array using bubble sort algorithm
	for j = 1; j < len; j++ {
		// Iterate through the array and compare each element with the current key
		for i = 0; i < len; i++ {
			// If the current element is not the first one, print it with a space
			if i!= 0 {
				fmt.Print(" ", a[i])
			} else {
				fmt.Print(a[i])
			}
		}
		// Print a new line after each pass
		fmt.Println()

		// Set the current key to the next element
		key = a[j]

		// Swap the current key with the previous element if it is greater
		for i = j - 1; i >= 0 && a[i] > key; i-- {
			a[i+1] = a[i]
		}

		// Swap the current key with the previous element
		a[i+1] = key
	}

	// Print the sorted array
	for i = 0; i < len; i++ {
		// If the current index is not the first one, print it with a space
		if i!= 0 {
			fmt.Print(" ", a[i])
		} else {
			fmt.Print(a[i])
		}
	}
	// Print a new line after printing the sorted array
	fmt.Println()
}

