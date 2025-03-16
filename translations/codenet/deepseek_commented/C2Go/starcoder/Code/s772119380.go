<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var a []int
	var n, i, j, d int

	// Read the number of elements in the array
	fmt.Scanf("%d", &n)

	// Read the elements of the array
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	// Bubble sort algorithm to sort the array in ascending order
	for i = 0; i < n; i++ {
		for j = n - 1; j >= i + 1; j-- {
			if a[j] < a[j - 1] {
				// Swap the elements if they are in the wrong order
				a[j], a[j - 1] = a[j - 1], a[j]
				// Increment the swap counter
				d++
			}
		}
	}

	// Print the sorted array
	fmt.Printf("%d", a[0])
	for i = 1; i < n; i++ {
		fmt.Printf(" %d", a[i])
	}
	fmt.Printf("\n")

	// Print the number of swaps made during the sorting process
	fmt.Printf("%d\n", d)
}

