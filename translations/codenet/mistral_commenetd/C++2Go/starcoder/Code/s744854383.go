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
	// Read the number of elements from the standard input
<<<<<<< HEAD
	N, _ := strconv.Atoi(strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString()))
=======
	N, _ := strconv.Atoi(strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString('\n')))
>>>>>>> 98c87cb78a (data updated)

	// Allocate memory for the array and read its elements
	a := make([]int, N)
	for i := 0; i < N; i++ {
<<<<<<< HEAD
		a[i], _ = strconv.Atoi(strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString()))
=======
		a[i], _ = strconv.Atoi(strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString('\n')))
>>>>>>> 98c87cb78a (data updated)
	}

	// Initialize variables
	idx := 1
	ans := 0

	// Process the array
	for i := 0; i < N; i++ {
		// Check if the current element matches the index
		if a[i] == idx {
			// Increment the index
			idx++
		} else {
			// Increment the answer
			ans++
		}
	}

	// Output the result
	if idx == 1 {
		fmt.Println(-1) // Output -1 if all elements are the same
	} else {
		fmt.Println(ans) // Output the answer otherwise
	}
}

